- 执行用时 :2 ms, 在所有 C 提交中击败了100.00%的用户
- 内存消耗 :8.4 MB, 在所有 C 提交中击败了100.00%的用户

```
int maxCount(int m, int n, int** ops, int opsSize, int* opsColSize){
    int min_r = 0x3f3f3f3f;
    int min_c = 0x3f3f3f3f;
    for (int i = 0; i < opsSize; ++i) {
        if (ops[i][0] < min_r) {
            if (ops[i][0] >= m) min_r = m;
            else                min_r = ops[i][0];
        }
        if (ops[i][1] < min_c) {
            if (ops[i][1] >= n) min_c = m;
            else                min_c = ops[i][1];
        }
    }
    if (min_r == 0x3f3f3f3f) return m*n;  //处理没有操作的情况

    return min_r*min_c;
}
```








