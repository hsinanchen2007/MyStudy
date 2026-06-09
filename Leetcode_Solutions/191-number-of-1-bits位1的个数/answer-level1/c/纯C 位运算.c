### 解题思路
纯C 位运算
### 代码

```c
int hammingWeight(uint32_t n) {
    int res = 0;

    while (0 != n)
    {
        n = (n & (n - 1)); // 每次会把一个1变成0;
        res++;
    }

    return res;
}
```