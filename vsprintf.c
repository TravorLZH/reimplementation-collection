#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#ifndef	BUFSIZ
#define	BUFSIZ	512
#endif
// Reference: https://stackoverflow.com/questions/16647278/minimal-implementation-of-sprintf-or-printf
int my_vsprintf(char* buffer,const char *format,va_list vlist){
	// TODO: Implementations
	int int_temp;
	char char_temp;
	char* string_temp;
	char buf_temp[BUFSIZ];

	char ch;
	size_t offset=0;

	while(ch=*(format++)){
		if('%'==ch){
			switch(ch=*format++){
				// %%
				case '%':
				*(buffer+offset)='%';
				offset++;
				break;
				// %c: Print out character
				case 'c':
				*(buffer+offset)=va_arg(vlist,int);
				offset++;
				break;
				// %s: Print out string
				case 's':
				string_temp=va_arg(vlist,char*);
				memcpy(buffer+offset,string_temp,strlen(string_temp));
				offset+=strlen(string_temp);
				break;
				// Print out an int
				case 'd':
				int_temp=va_arg(vlist,int);
				itoa(int_temp,buf_temp);
				memcpy(buffer+offset,buf_temp,strlen(buf_temp));
				offset+=strlen(buf_temp);
				break;
			}
		}else{
			*(buffer+offset)=ch;
			offset++;
		}
	}
	*(buffer+offset)='\0';	// Null Terminator
	return offset;
}

int my_sprintf(char* buf,const char* fmt,...){
	va_list vl;
	va_start(vl,fmt);
	int rs=my_vsprintf(buf,fmt,vl);
	va_end(vl);
	return rs;
}

