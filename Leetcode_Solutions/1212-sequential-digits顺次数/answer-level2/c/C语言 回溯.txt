### 解题思路
C语言 回溯

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b)
{
    return *(int *)a-*(int *)b;
}
/*
    len: 记录返回数组的长度
    curnum：当前需要判断的数
    digit：最低位的数值
 */
void dfs(int low, int high, int *ans, int *len, int curnum, int digit)
{
    if (curnum >= low && curnum <= high) {
        ans[*len] = curnum;
        (*len)++;
    }
    if (curnum > high) {
        return;
    }
    if (digit + 1 <= 9) {
        dfs(low, high, ans, len, (curnum * 10 + digit + 1), digit + 1);
    }
    
}
int* sequentialDigits(int low, int high, int* returnSize){
    int *ans = (int*)malloc(sizeof(int) * 2048);
    int len = 0;
    for (int i = 1; i <= 9; i++) {
        dfs(low, high, ans, &len, i, i);
    }
    *returnSize = len;
    qsort(ans, len, sizeof(int), cmp);
    return ans;
}
```