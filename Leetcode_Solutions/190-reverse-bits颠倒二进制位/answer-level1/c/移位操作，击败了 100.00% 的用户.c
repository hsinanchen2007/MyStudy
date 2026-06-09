### 解题思路
移位

### 代码

```c
uint32_t reverseBits(uint32_t n) {
    uint32_t i = 0;
    int x;
    for (x = 0; x < 31; x++)
    {
        i |= (n & 1);
        i <<= 1;
        n >>= 1;
    }
    i |= (n & 1);
    return i;
}
```