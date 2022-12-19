### 解题思路
要把字符变成数字，再把数字变成字符
### 代码

```c
char * complexNumberMultiply(char * a, char * b){
    char *s,t;
    s=(char*)malloc(sizeof(char)*20);
    int e=0,f=0,c=0,d=0,i,j,flag1,flag2,flag3,flag4;
    i=0;
    flag1=0;
    if(a[0]=='-') i=1,flag1=1;
    for(;a[i]!='\0';i++){
        if(a[i]>='0'&&a[i]<='9')
            c=c*10+a[i]-'0';
        else break;
    }
    if(flag1==1) c=-c;
    flag3=0;
    for(;a[i]!='\0';i++){
        if(a[i]>='0'&&a[i]<='9'){
            if(a[i-1]=='-') flag3=1;
            e=e*10+a[i]-'0';
        }
        else if(a[i]=='i') break;   
    }
    if(flag3==1) e=-e;
    i=0;
    flag2=0;
    if(b[0]=='-') i=1,flag2=1;
    for(;b[i]!='\0';i++){
        if(b[i]>='0'&&b[i]<='9')
            d=d*10+b[i]-'0';
        else break;
    }
    if(flag2==1) d=-d;
    flag4=0;
    for(;b[i]!='\0';i++){
        if(b[i]>='0'&&b[i]<='9'){
            if(b[i-1]=='-') flag4=1;
            f=f*10+b[i]-'0';
        }
        else if(b[i]=='i') break;   
    }
    if(flag4==1) f=-f;
    int l,m,n,p;
    printf("c=%d e=%d d=%d f=%d\n",c,e,d,f);
    l=c*d,m=c*f,n=e*d,p=e*f;
    l=l-p,m=m+n;
    printf("l=%d m=%d\n",l,m);
    i=0;
    flag1=0;
    if(l==0) s[i++]='0';
    else{
        if(l<0) s[i++]='-',l=-l,flag1=1;
        while(l!=0){
            s[i++]=l%10+'0';
            l=l/10;
        }
        if(flag1==1) j=1;
        else j=0;
        p=i-1;
        while(j<p){
            t=s[j];
            s[j]=s[p];
            s[p]=t;
            j++;
            p--;
        }
    }
    s[i++]='+';
    if(m==0) s[i++]='0';
    else{
        if(m<0) s[i++]='-',m=-m;
        j=i;
        while(m!=0){
            s[i++]=m%10+'0';
            m=m/10;
        }
        p=i-1;
        while(j<p){
            t=s[j];
            s[j]=s[p];
            s[p]=t;
            j++;
            p--;
        }
    }
    s[i++]='i';
    s[i]='\0';
    return s;
}
```