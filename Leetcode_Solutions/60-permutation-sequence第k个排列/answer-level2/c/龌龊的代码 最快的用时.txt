### 解题思路
此处撰写解题思路

### 代码

```c
int ji(int a,int b)
{
    if(a%b==0)
    return a/b;
    else
    return a/b+1;
}
int jie(int x)
{
    int i = 1;
    while(1!=x)
    {
        i*=x;
        x--;
    }
    return i;
}
char * getPermutation(int n, int k){
char abc[9]="123456789";
char *a=(char*)malloc(sizeof(char)*(n+1));
a[n]='\0';
int i = n;
int yuan=1;
while(i--)
{
    if(yuan)
    {
        int ii=0;
        if(1 == k||2==k)
        {
           for(;ii<n;ii++)
           a[ii]=abc[ii];
        
        if(2==k)
        {
            ii-=1;
           a[ii]=a[ii]^a[ii-1];
           a[ii-1]=a[ii]^a[ii-1];
           a[ii]=a[ii]^a[ii-1];
        }
        break;
        }
        else{
            i+=1;
            yuan=0;
        }
    }
    else{
    if(1==k||2==k)
    {
        int yy=n-i-1;
        int xx=0;
        for(;yy<n;yy++)
        {
            a[yy]=abc[xx];
            xx++;
        }
       // a[n-i-1]=abc[0];
       //a[n-i]=abc[1];
    //    break;
    
     if(2== k)
    {
        yy-=1;
        a[yy]^=a[yy-1];
        a[yy-1]^=a[yy];
        a[yy]^=a[yy-1];
    }
break;
    }
    else{
        int zhi=ji(k,jie(i))-1;
        a[n-i-1]=abc[zhi];
        k=k-zhi*jie(i);
        yuan=0;
        for(;zhi<i;zhi++)
        {
            abc[zhi]=abc[zhi+1];
        }
    }}
}
for(int o=0;o<n;o++)
{
    printf("%c",a[o]);
}
return a;
}
```