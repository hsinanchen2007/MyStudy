### 解题思路
此处撰写解题思路

### 代码

```c
char * addBinary(char * a, char * b){
char *p=a,*q=b,*c=NULL;
int k=0,size,i,la,lb;
size=strlen(a)>strlen(b)?strlen(a)+2:strlen(b)+2;
la=strlen(a);
lb=strlen(b);
c=(char *)malloc(size);
memset(c,'0',size);
c[size-1]='\0';
for(i=1;i<=size-1;i++){
    if(la-i>=0) c[size-1-i]+=p[la-i]+0-'0';
    if(lb-i>=0) c[size-1-i]+=q[lb-i]+0-'0';
    c[size-1-i]+=k;
    if(c[size-1-i]=='2'||c[size-1-i]=='3'){ 
        c[size-1-i]=c[size-1-i]-2;
        k=1;
     }else k=0;
}
if(*c=='0') c++;
return c;
}
```