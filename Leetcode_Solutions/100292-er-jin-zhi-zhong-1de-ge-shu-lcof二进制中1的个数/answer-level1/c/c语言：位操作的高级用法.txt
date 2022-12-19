去掉一个数n中的最后一位二进制位上的1的操作：`n = n & (n - 1)`
```
int hammingWeight(uint32_t n) {
    int res = 0;

    while (n != 0) {
        n = n & (n - 1);
        res++;
    }

    return res;
}
```
