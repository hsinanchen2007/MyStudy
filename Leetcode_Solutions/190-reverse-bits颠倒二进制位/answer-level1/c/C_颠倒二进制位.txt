### 解题思路
n%2就是提取最低位
num*2就是左移一位

### 代码

```c
uint32_t reverseBits(uint32_t n) {
    uint32_t num=0;
    for(int i=0;i<32;i++)
    {
        num=num*2+n%2;
        n=n/2;
    }
    return num;
}
```