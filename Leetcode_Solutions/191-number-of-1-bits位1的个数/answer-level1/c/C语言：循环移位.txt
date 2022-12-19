执行用时 :4 ms, 在所有 C 提交中击败了74.59%的用户
内存消耗 :6.7 MB, 在所有 C 提交中击败了6.02%的用户

```c
int hammingWeight(uint32_t n) {
    int ret = 0;
    for ( ; n != 0; n = n >> 1) {
        ret += (n & 1);
    }
    return ret;
}
```

内存消耗只击败了6.02%的用户，怎么优化内存呢？？