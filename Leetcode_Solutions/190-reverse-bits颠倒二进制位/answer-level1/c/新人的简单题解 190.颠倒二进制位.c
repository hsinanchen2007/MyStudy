### 解题思路
n的倒数第一位就是temp的第一位，所以，通过位移运算符不断取n的倒数第1位，放在temp末尾然后temp左移就好。

### 代码

```c
uint32_t reverseBits(uint32_t n)
{
   uint32_t temp=n&1;
    for(int i=1;i<32;i++)
    {
        temp<<=1;
        temp+=(n>>i)&1;
    }
    return temp;
}
```