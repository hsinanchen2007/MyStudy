### 解题思路
此处撰写解题思路
第一次写（新手）变量稍多！分两种情况（感觉有些多余的判断但我想不到怎样解决）
或许看看别的大神的就知道了！
(1)加后位数不变(2)加后位数加一（第一位定为1）
其中 x为判断是那种情况   q判断需要进1。
### 代码

```c
char * addBinary(char * a, char * b){
int q=0,m,e,x=1;
int i,j;
char * n;
char * p;
int c=strlen(a),d=strlen(b);
if(c>=d){m=c;e=d;}
else{m=d;e=c;}
if(c>=d){
    for(i=c-1,j=d-1;i>-1;i--,j--){
    if(j>=0)
       a[i]+=b[j]-'0';
    }
    n=a;
}
else {
    for(i=d-1,j=c-1;i>-1;i--,j--){
    if(j>=0)
       b[i]+=a[j]-'0';
    }
    n=b;
}
for(i=m-1;i>=0;i--){
    if(n[i]=='2')x=2;
    else if(x==2&&n[i]=='1')x=2;
    else x=1;
}
p=(char*)malloc(sizeof(char)*(m+2));
p[m+1]='\0';

for(i=m-1;i>0;i--)
{
    if(n[i]=='2')
    {
        n[i]='0';
        q=1;
        n[i-1]+=q;
    }
    else if(n[i]=='3')
    {
        n[i]='1';
        q=1;
        n[i-1]+=q;
        
    }
    if(i==1)
    {
        if(n[0]=='3')n[0]='1';
        else if(n[0]=='2')n[0]='0';
    }
}

    if(x==2)
    {   if(m==1)n[0]='0';
        for(i=0;i<m;i++)p[i+1]=n[i];
        p[0]='1';
        return p;
    }
    else if(x==1)
    {
        for(i=0;i<m;i++)p[i+1]=n[i];
        return &p[1];
    }
return p;
}
```