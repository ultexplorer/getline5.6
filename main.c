#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 1000
int my_getline(char *s, int lim);
int my_atoi(char *s);
void my_itoa(int n, char *s);
void reverse(char *s);
int strindex(char *s, char *t);

int main()
{
    char str[SIZE]="";
    int y=my_getline(str, SIZE);
    printf("\n%d %s\n", y, str);

    char s1[]=" 123";
    printf("%d\n", my_atoi(s1));

    my_itoa(127, str);
    printf("%s\n", str);

    char s2[SIZE]="hro hru hren hron hue";
    char s3[]="hron";
    y=strindex(s2, s3);
    printf("y=%d\n", y);

    return 0;
}

int my_getline(char *s, int lim)
{
    int c;
    char *t=s;
    while(--lim>0 && (c=getchar())!=EOF && c!='\n'){
        *s++=c;
    }
    if(c=='\n'){
        *s++=c;
    }
    *s='\0';
    return s-t;
}

int my_atoi(char *s)
{
    int n, sign;
    for(;isspace(*s);s++); //пропускаем пробелы
    sign=(*s=='-')? -1: 1;
    if(*s=='+' || *s=='-') s++;
    for(n=0; isdigit(*s); s++){
        n=10*n + (*s -'0');
    }
    return sign*n;
}

void my_itoa(int n, char *s)
{
    int sign;
    char *t=s;
    if((sign=n)<0) n=-n;
    do{
        *s++=n%10+'0';
    }while((n/=10)!=0);
    if(sign<0) *s++='-';
    *s='\0';
    reverse(t);
}

void reverse(char *s)
{
    int c;
    char *t;
    for(t=s+(strlen(s)-1); s<t; s++, t--){
        c=*s;
        *s=*t;
        *t=c;
    }
}

int strindex(char *s, char *t)
{
    char *b=s;
    char *p, *r;
    for(;*s!='\0';s++){
        for(p=s, r=t; *r!='\0' && *p==*r; p++, r++);
        if(r>t && *r=='\0') return s-b;
    }
    return -1;
}
