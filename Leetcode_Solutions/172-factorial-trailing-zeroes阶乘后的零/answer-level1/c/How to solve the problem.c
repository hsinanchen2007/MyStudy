### 解题思路
想一想零是怎么产生的

### 代码

```c
int trailingZeroes(int n)
{
    int result=0;
    

    while(n/=5)
    {
        result+=n;
    }

   
    return result;
}
```