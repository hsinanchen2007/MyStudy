### 解题思路
此处撰写解题思路
1、就是一个移位操作

### 代码

```c
uint32_t reverseBits(uint32_t n) {
    int num = 0;
    uint32_t results = 0;

    for(num = 0; num < 32; num++)
    {
        results += pow(2, 31 - num) * (n & 1);
        n = n >> 1;
    }

    return results;
}
```