### 解题思路
执行用时 :248 ms, 在所有 C 提交中击败了30.51%的用户
内存消耗 :7.8 MB, 在所有 C 提交中击败了100.00%的用户

### 代码

```c
#define MAXNUM 100000

int Comp(const void *a, const void *b)
{
    int **aa = (int**)a;
    int **bb = (int**)b;

    if (aa[0][0] == bb[0][0]) {
        return aa[0][1] - bb[0][1];
    }

    return aa[0][0] - bb[0][0];
}

void Dfs(int** intervals, int node, int intervalsSize, int visit[])
{
    if (visit[node] == 1) {
        return;
    }

    visit[node] = 1;

    for (int i = 0; i < intervalsSize; i++) {
        if (!visit[i] && intervals[node][1] <= intervals[i][0]) {
            Dfs(intervals, i, intervalsSize, visit);
            break;
        }
    }
}

int minMeetingRooms(int** intervals, int intervalsSize, int* intervalsColSize)
{
    qsort(intervals, intervalsSize, sizeof(intervals[0]), Comp);

    int visit[MAXNUM] = {0};
    int num = 0;

    for (int i = 0; i < intervalsSize; i++) {
        if (visit[i] == 0) {
            Dfs(intervals, i, intervalsSize, visit);
            num++;
        }
    }

    return num;
}
```