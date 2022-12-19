### 解题思路
回溯成功的关键是k不能自加，而是在不断回溯的过程加1，而k的值不修改，不然就容易陷入死循环。
即代码里的k的操作。
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAXLEN (2000)
int g_num = 0;
void backtrack(char *tmp, char **res, int left, int right, int n, int k)
{
    if (left == n && right == n) {
        res[g_num] = (char*)malloc(2*n+1);
        memset(res[g_num], 0, 2*n+1);
        strcpy(res[g_num], tmp);   
        g_num++;
        return;
    }
    if (left < right) {
        return;
    }
    if (left + 1 <= n) {
        tmp[k] = '(';
        backtrack(tmp, res, left + 1, right, n, k+1);
    }
    if (right + 1 <= n) {
        tmp[k] = ')';
        backtrack(tmp, res, left, right + 1, n, k+1);
    }
}
char ** generateParenthesis(int n, int* returnSize){    
    char **res = (char**)malloc(MAXLEN * sizeof(char*));    
    *returnSize = 0;
    if (n == 0) {
        res[0] = "";
        return res;
    }
    g_num = 0;
    char *tmp = (char*)malloc(2*n+1);
    memset(tmp, 0, 2*n+1);
    backtrack(tmp, res, 0, 0, n, 0);
    free(tmp);
    *returnSize = g_num;
    return res;
}
```