### 解题思路
这道题是一道进制转换问题，可以类比10进制问题的处理方法
while(n>0){
    存储个位;
    抹去个位;
}
开了一个数组a和数组r，分别存储字母A-Z和转换后的结果，n-1因为数组下标从0开始。
每次从低位开始存储，最后需要逆转一下数组，从高位开始输出。

### 代码

```c
void reverse(char *r,int len)
{
    for(int i=0,j=len-1;i<j;++i,--j){
        char tmp=r[i];
        r[i]=r[j];
        r[j]=tmp;
    }
}

char * convertToTitle(int n)
{
    char *r=malloc(sizeof(char)*27);
    char *a=malloc(sizeof(char)*27);
    int index=0;
    for(int i=0;i<26;++i)
        a[i]='A'+i;
    while(n>0){
        r[index++]=a[(n-1)%26];
        n=(n-1)/26;
    }
    r[index]='\0';
    reverse(r,index);
    return r;
}
```

后来，我发现开一个数组就可以了。

### 代码

```c
void reverse(char *r,int len)
{
    for(int i=0,j=len-1;i<j;++i,--j){
        char tmp=r[i];
        r[i]=r[j];
        r[j]=tmp;
    }
}

char * convertToTitle(int n)
{
    char *r=malloc(sizeof(char)*27);
    int index=0;
    while(n>0){
        r[index++]='A'+(n-1)%26;
        n=(n-1)/26;
    }
    r[index]='\0';
    reverse(r,index);
    return r;
}
```