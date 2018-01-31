#include <stdio.h>

int main(void){
	char* num="-23123";
	int x=my_atoi(num);
	printf("%d\n",x);
	int n;
	printf("Enter the integer to convert: ");
	scanf("%d",&n);
	char str[10];
	itoa(n,str);
	printf("Converted: %s\n",str);
	char buf[100];
	my_sprintf(buf,"I am %d years old\n",13);
	printf(buf);
	return 0;
}

