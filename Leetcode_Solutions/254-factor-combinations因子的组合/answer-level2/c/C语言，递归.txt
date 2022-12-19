```
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int midAns[1000];
int g_ans[1000][1000];
int g_colans[1000];
int g_num;
int toalnum;
void f(int n, int x, int m) 
{
    int i;
    if ((n == 1) && (m != 1)) {
        for (i = 0; i < g_num; i++) {
            g_ans[toalnum][i] = midAns[i];
        }
        g_colans[toalnum] = g_num;
        toalnum++;
        return;
    }
    for (i = 2; i <= n; i++) {
        if (i < x) {
            continue;
        }
        if ((n % i == 0) && (n / i != m) && (i != m)) {
            midAns[g_num] = i;
            g_num++;
            f(n / i, i, m);
            g_num--;
        }
    }
}
int** getFactors(int n, int* returnSize, int** returnColumnSizes)
{
    int **ans, i, j;
    toalnum = 0;
    g_num = 0;
    f(n, 1, n);
    *returnSize = toalnum;
    ans = (int**)malloc(sizeof(int*) * toalnum);
    *returnColumnSizes = (int*)malloc(sizeof(int) * toalnum);
    for (i = 0; i < toalnum; i++) {
        ans[i] = (int*)malloc(sizeof(int) * g_colans[i]);
        (*returnColumnSizes)[i] = g_colans[i];
        for (j = 0; j < g_colans[i]; j++) {
            ans[i][j] = g_ans[i][j];
        }
    }
    return ans;
}
```
