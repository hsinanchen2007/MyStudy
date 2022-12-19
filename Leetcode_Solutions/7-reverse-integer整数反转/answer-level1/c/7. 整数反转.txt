```c
#define MAX 2147483647  // 2^32 - 1

int mabs(int x) // 绝对值
{
    if(x<0)
        x=-x;
    return x;
}

int reverse(int x){
    int ret=0;
    
    if(x==(-MAX-1))
    {
        return 0;
    }
    
    while(x)
    {
        ret = ret*10+x%10;
        x=x/10;
        if(mabs(ret)>((MAX)/10))
        {
            if(x!=0)
                return 0;
        }    
    }
    return ret;
    
}
```
