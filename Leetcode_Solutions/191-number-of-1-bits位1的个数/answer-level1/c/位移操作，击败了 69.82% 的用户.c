### 解题思路
此处撰写解题思路

### 代码

```c
int hammingWeight(uint32_t n) {
    int count = 0;
    while (n != 0)
    {
        if (n & 1 == 1) count++;
        n = n >> 1;
    }
    return count;
}
```