#include <stdlib.h>

char* strrev(char* str){
	char* start=str;
	char* end=str;
	char temp=0;
	while(*(end++));
	end--;  // Compensate end++
	end--;  // Ignore the \0
	while(start<end){
		temp=*start;
		*start++=*end;
		*end--=temp;
	}
	return str;
}

void itoa(int n,char *s){
	char neg=0;
	char *x=s;
	if(n<0){
		neg=1;
		n=-n;
	}
	do{
		*x=n%10+'0';
		x++;
	}while(n/=10);
	if(neg){
		*x='-';
		x++;
	}
	*x='\0';
	strrev(s);
}
