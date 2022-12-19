### 解题思路


### 代码

```c
int reverse(int x)
{
    long y=0;
    while(x!=0)
    {
        y=y*10+x%10;
        x/=10;
    }
    if((int)y != y)
    {
        return 0;
    }
    return y;
}
```