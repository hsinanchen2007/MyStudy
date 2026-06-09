### 解题思路
1135. 最低成本联通所有城市 和这次一样的解法

### 代码

```c
#define MAXLEN 101

int g_parent[MAXLEN];

int Comp(const void *a, const void *b)
{
    int **aa = (int **)a;
    int **bb = (int **)b;

    return aa[0][0] - bb[0][0];
}

int Find(int a)
{
    while (a != g_parent[a]) {
        a = g_parent[a];
    }

    return a;
}

void Connect(int a, int b)
{
    int aa = Find(a);
    int bb = Find(b);

    if (aa != bb) {
        g_parent[aa] = bb;
    }
}

int earliestAcq(int** logs, int logsSize, int* logsColSize, int N)
{
    qsort(logs, logsSize, sizeof(int *), Comp);

    for (int i = 0; i < N; i++) {
        g_parent[i] = i;
    }

    int num = 0;

    for (int i = 0; i < logsSize; i++) {
        int aa = Find(logs[i][1]);
        int bb = Find(logs[i][2]);

        /* 如果祖先相同，继续 */
        if (aa == bb) {            
            continue;
        }

        /* 建立关系 */
        Connect(logs[i][1], logs[i][2]);

        if (++num == N - 1) {
            return logs[i][0];
        }
    }

    return -1;
}
```