#include <string.h>

int my_atoi(const char* nptr){
	char* x=(char*)nptr;
	int res=0;
	int sign=1;
	int i=0;
	if(x[0]=='-'){
		sign=-1;
		x++;
	}else if(x[0]=='+'){
		x++;
	}
	char* s=x+strlen(x);
	while(x<s){
		res=res*10+*x-'0';
		x++;
	}
	return sign*res;
}

