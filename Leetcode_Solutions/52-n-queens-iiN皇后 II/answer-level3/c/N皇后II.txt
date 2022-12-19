### 解题思路
1.逐行放置，每一行遍历每一列
2.当前行遍历列时，判断当前位置是否与前几行有列冲突和对角线冲突
### 代码

```c
int g_total = 0;
int *g_visit = NULL;

void Search(int k, const int n)
{
    int i = 0;
    int j = 0;
    int ok = 1;

    if (k == n) {
        g_total++;
        return;
    }

    for (i = 0; i < n; i++) {               // 尝试放置第i列
        ok = 1;                             // 假定可以放置
        for (j = 0; j < k; j++) {           // 确认是否与前k行冲突
            if ((g_visit[j * n + i] == 1) ||
                ((i + j) >= k && g_visit[j * n + (i + j - k)] == 1) ||
                ((i + k - j) < n && g_visit[j * n + (i + k - j)] == 1)) {
                ok = 0;                     // 同一列,左右对角线冲突
            }
        }

        if (ok) {
            g_visit[n * k + i] = 1;
            Search(k + 1, n);               // 不冲突继续找下一行
            g_visit[n * k + i] = 0;
        }
    }
}

int totalNQueens(int n)
{
    int len = sizeof(int) * n * n;

    g_visit = (int *)malloc(len);
    memset(g_visit, 0, len);
    g_total = 0;
    Search(0, n);

    return g_total;
}
```