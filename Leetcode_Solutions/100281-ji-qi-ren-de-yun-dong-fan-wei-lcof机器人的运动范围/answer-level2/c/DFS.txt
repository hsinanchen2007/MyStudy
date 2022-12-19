思路：
    深度优先搜索，统计走过的格子数。通过二维数组walked中元素的值标标记格子是否被走过。
    需要注意的是，走过的格子在walked二维数组中被置为1后不要在返回时清0，因为已经被统计了，如果清零的话会造成重复统计。

代码：

#define MAX_DIR 4

bool IsValidPoint(int x, int y, int k)
{
    int sum = 0;
    
    while (x != 0) {
        sum += x % 10;
        x = x / 10;
    }
    while (y != 0) {
        sum += y % 10;
        y = y / 10;
    }

    return (sum <= k);
}

int BackTrace(int m, int n, int **walked, int p, int q, int k)
{
    int dir[MAX_DIR][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int i;
    int count = 0;

    if (p < 0 || q < 0 || p >= m || q >= n) {
        return 0;
    }

    if (*(*(walked + p) + q) == 1) {
        return 0;
    }

    *(*(walked + p) + q) = 1;

    for (i = 0; i < MAX_DIR; i++) {
        count += BackTrace(m, n, walked, p + dir[i][0], q + dir[i][1], k);
    }

    return 1 + count;
}

int **AllocWalked(int m, int n)
{
    int **walked = NULL;
    int i;

    walked = (int **)malloc(sizeof(int *) * m);
    for (i = 0; i < m; i++) {
        walked[i] = (int *)malloc(sizeof(int) * n);
        memset(walked[i], 0, sizeof(int) * n);
    }

    return walked;
}

void FreeWalked(int **walked, int m)
{
    int i;

    for (i = 0; i < m; i++) {
        free(walked[i]);
    }
    free(walked);

    return;
}

int movingCount(int m, int n, int k){
    int **walked = NULL;
    int i, j;
    int count;

    walked = AllocWalked(m, n);

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (!IsValidPoint(i, j, k)) {
                walked[i][j] = 1;
            }
        }
    }

    count = BackTrace(m, n, walked, 0, 0, k);

    FreeWalked(walked, m);

    return count;
}