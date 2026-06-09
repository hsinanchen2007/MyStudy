### 解题思路
纯C 反转位操作模板

### 代码

```c
uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    int index = 0;

    for (index = 0; index < 32; index++)
    {
        res = (res << 1) | (n & 1);
        n >>= 1;
    }

    return res;
}
```