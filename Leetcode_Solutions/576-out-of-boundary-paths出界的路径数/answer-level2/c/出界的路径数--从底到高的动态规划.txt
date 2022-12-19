矩阵类的处理，通常都是从周边走入到当前位置，之前其他的处理都是从上或者从左走过来，典型的动态规划处理。

该题是找出从周边4个位置[(i - 1, j), (i + 1, j), (i, j + 1), (i, j - 1)]分别一步走入(i , j)均只需要一步。那么从这4个位置走N - 1步的步数之和，就是从(i, j)走N步的步数。

定义DP[i, j , N]为从(i, j)位置走到边界的步数，该步数可以通过4个位置走入：
    DP[i, j, N] = DP[i, j + 1, N-1] + DP[i, j - 1, N - 1] + DP[i + 1, j, N - 1] + DP[i - 1, j, N - 1]

由于i，j, N都是一个很大的值，那么可以通过走1步出界的步数计算，然后归并到N步，即一个从底到高的动态规划过程。

每一轮的N处理都是一个新的状态集合，通过不停的状态集合更新。
```
#define DIRECTION   4
#define TWOSTEP     2
#define MODNUM      1000000007

int CheckParam(int m, int n, int N, int i, int j)
{
    if (m <= 0 || n <= 0 || N <= 0 || i < 0 || j < 0) {
        return -1;
    }

    if (i >= m || j >= n) {
        return -1;
    }

    return 0;
}

unsigned long long* initState(int m, int n)
{
    unsigned long long *result = (unsigned long long *)malloc(sizeof(unsigned long long) * n * m);
    if (result == NULL) {
        return NULL;
    }

    memset(result, 0, sizeof(unsigned long long) * n * m);
    
    int directions[DIRECTION][TWOSTEP] = {
        { 1, 0 },
        { -1, 0 },
        { 0, 1 },
        { 0, -1 }
    };

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < DIRECTION; ++k) {
                int newX = directions[k][0] + i;
                int newY = directions[k][1] + j;
                if (newX < 0 || newX >= m || newY < 0 || newY >= n) {
                    result[i * n + j] += 1;
                }
            }
        }
    }

    return result;
}

void nextState(unsigned long long *prevState, unsigned long long *nextState, int m, int n)
{
    int directions[DIRECTION][TWOSTEP] = {
        { 1, 0 },
        { -1, 0 },
        { 0, 1 },
        { 0, -1 }
    };

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < DIRECTION; ++k) {
                int newX = directions[k][0] + i;
                int newY = directions[k][1] + j;
                if (newX >= 0 && newX < m && newY >= 0 && newY < n) {
                    nextState[i * n + j] += prevState[newX * n + newY];
                }
            }
            nextState[i * n + j] = nextState[i * n + j] % MODNUM;
        }
    }
}

int findPaths(int m, int n, int N, int i, int j)
{
    if (CheckParam(m, n, N, i, j)) {
        return 0;
    }

    unsigned long long *start = initState(m, n);
    unsigned long long *next = (unsigned long long *)malloc(sizeof(unsigned long long) * n * m);
    memset(next, 0, sizeof(unsigned long long) * n * m);
    unsigned long long cnt = start[i * n + j];
    for (int k = 2; k <= N; ++k) {
        nextState(start, next, m, n);
        memcpy(start, next, sizeof(unsigned long long) * n * m);
        cnt += start[i * n + j];
        memset(next, 0, sizeof(unsigned long long) * n * m);
    }

    free(next);
    free(start);

    return (int)(cnt % MODNUM);
}
```

