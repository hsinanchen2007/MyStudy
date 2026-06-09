### 解题思路
暴力循环，不断除三，看最后剩下的是不是1就好了

### 代码

```c
bool isPowerOfThree(int n)
{
    if(n<=0) return false;
    else
    {
        while(n%3==0)
        {
            n/=3;
        }
        return n==1;
    }
}
```