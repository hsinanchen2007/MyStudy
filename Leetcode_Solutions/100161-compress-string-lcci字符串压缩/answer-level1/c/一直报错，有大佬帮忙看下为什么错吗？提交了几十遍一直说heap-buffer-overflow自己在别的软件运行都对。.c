#include<stdio.h>
#include<math.h>
char* compressString(char* S){
int i;int count=1;
int len=strlen(S);
char *s=(char *)malloc(sizeof(char)*2*len);
s[0]=S[0];
int k=1;
int a[5];
int b=0;
for(i=0;i<len;i++)
{
if(S[i]==S[i+1])
{
    count++;
}
else {
    if(count>=10)
    {  while(count!=0)
    {
        a[b]=count%10;
        count=count/10;
        b++;
    }
    while(b>0)
{s[k]=a[--b]+48;
k++;}
s[k]=S[i+1];
k++;
        count=1;
    }
else {
s[k]=count+48;
k++;
s[k]=S[i+1];
k++;
count=1;
}
}
}
if(k-2<len)
return s;
else return S;
}