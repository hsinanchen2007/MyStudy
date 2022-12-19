### 解题思路
本题比较麻烦的地方在于处理输出指针
1.逐行放置，每一行遍历每一列
2.当前行遍历列时，判断当前位置是否与前几行有列冲突和对角线冲突
3.在回溯函数里记录了当前解法种数，根据visit map里记录的值，填入'Q' 或 '.'
### 代码

```c

void GenOut(const int n, int cnt, int *visit, char ***ret)
{
    int i, j;
    for (i = 0; i < n; i++) {
        ret[cnt][i] = (char *)malloc(sizeof(char) * (n + 1));
        for (j = 0; j < n; j++) {
            if (visit[i * n + j]) {
                ret[cnt][i][j] = 'Q';
            } else {
                ret[cnt][i][j] = '.';
            }
        }
        ret[cnt][i][j] = '\0';
    }
}

void Search(int k, const int n, int *cnt, int *visit, char ***ret)
{
    int i = 0;
    int j = 0;
    int ok = 0;

    if (k == n) {
        GenOut(n, *cnt, visit, ret);
        (*cnt)++;
        ret[*cnt] = (char **)malloc(sizeof(char *) * n);
        return;
    }

    /* 0,0  0,1  0,2
       1,0  1,1  1,2
       2,0  2,1  2,2
    */

    for (i = 0; i < n; i++) {
        ok = 1;
        for (j = 0; j < k; j++) {
            if (visit[j * n + i] ||
                (i + j >= k && visit[j * n + (i + j - k)]) ||
                (k + i - j < n && visit[j * n + (k + i - j)])) {
                ok = 0;
            }
        }

        if (ok) {
            visit[k * n + i] = 1;
            Search(k + 1, n, cnt, visit, ret);
            visit[k * n + i] = 0;
        }
    }
}

char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes)
{
    int visitLen = sizeof(int) * n * n;
    int *visit = malloc(visitLen);
    int cnt = 0;
    int i = 0;
    char ***ret = NULL;

    memset(visit, 0, visitLen);
    ret = (char ***)malloc(sizeof(char **) * 1000);
    ret[0] = (char **)malloc(sizeof(char *) * n);
    Search(0, n, &cnt, visit, ret);

    *returnSize = cnt;
    *returnColumnSizes = (int *)malloc(sizeof(int) * cnt);
    for (i = 0; i < cnt; i++) {
        (*returnColumnSizes)[i] = n;
    }

    return ret;    
}
```