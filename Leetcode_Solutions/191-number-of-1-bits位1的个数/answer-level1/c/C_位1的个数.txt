### 解题思路
位操作//常规操作

### 代码

```c
int hammingWeight(uint32_t n) {
    int result=0;
    while(n!=0)
    {
        if((uint32_t)1&n)// n%2==1;
            ++result;
        n=n>>1;// n/=2;
    }
    return result;
}
```