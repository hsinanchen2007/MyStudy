### 解题思路
此处撰写解题思路

### 代码

```c
int lengthOfLongestSubstring(char * s){
    int max=0,n=0;
    char *p1=s,*p2=s;
    while(*p1)
    {
        int flag=0;
        int i=0;
        for(;i<n;i++)
        {
            if(*p1==*(p2+i))
            {
                flag=1;
                p2=p2+i+1;
                break;
            }
        }
        if(flag==0)
            n++;
        if(n>max)
        {
            max=n;
        }
        if(flag==1)
        {
            n=n-i;
        }
        p1++;
    }
    return max;

}
```