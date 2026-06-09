### 解题思路
正常思路

### 代码

```c
void f1(char* s,int left,int right)
{
    while(left<right)
    {
        char temp=s[left];
        s[left]=s[right];
        s[right]=temp;
        left++;
        right--;
    }
}
char * reverseStr(char * s, int k){
    int len=strlen(s);
    int lengh=len;
    int cnt=0;
    int flag1=0;
    int flag2=0;
    while(len>2*k)
    {
        f1(s,cnt,cnt+k-1);
        cnt+=2*k;
        len-=2*k;
    }
    if(len<=k)
    {
        flag1=1;
        f1(s,cnt,lengh-1);
    }
    else if(len>k&&len<=2*k)
    {
        flag2=1;
        f1(s,cnt,cnt+k-1);
    }
    printf("%d\n%d",flag1,flag2);
    return s;
}
```