执行结果：通过
显示详情
执行用时 :8 ms, 在所有 c 提交中击败了100.00%的用户
内存消耗 :7.8 MB, 在所有 c 提交中击败了100.00%的用户

```
int *sumZero(int n, int *returnSize)
{
    if (n <= 0) {
        *returnSize = 0;
        return NULL;
    }
    int *res = malloc(n * sizeof(int));
    int total = 0;

    memset(res, 0, n *sizeof(int));
    for (int i = 1; i <= n / 2; i++) {
        res[total++] = i;
        res[total++] = -i;
    }
    if (n % 2) {
        res[total++] = 0;
    }
    *returnSize = total;
    return res;
}
```

