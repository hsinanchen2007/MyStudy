### 解题思路
DFS思路很清晰，但存在大量的重复计算，通过cache来保存已经递归遍历的结果进行优化后通过

### 代码

```c
int g_dir[2][2] = {{0, 1}, {1, 0}};

typedef struct tagPos {
    int x;
    int y;
} Pos;

int dfs(int **cache, Pos *step, Pos *end, Pos *max)
{
    if ((step->x < 0) || (step->y < 0) || (step->x >= max->x) || (step->y >= max->y)) {
        return 0;
    }

    if (cache[step->x][step->y] != 0) {
        return cache[step->x][step->y];
    }

    if ((step->x == end->x) && (step->y == end->y)) {
        return 1;
    }

    for (int i = 0; i < 2; i++) {
        Pos next = {
            .x = step->x + g_dir[i][0],
            .y = step->y + g_dir[i][1]
        };
        cache[step->x][step->y] += dfs(cache, &next, end, max);
    }

    return cache[step->x][step->y];
}

int uniquePaths(int m, int n){
    if (m <= 1 || n <= 1) {
        return 1;
    }
    int **cache = NULL;
    cache = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        cache[i] = (int *)malloc(n * sizeof(int));
        memset(cache[i], 0, n * sizeof(int));
    }

    Pos start = {0};
    Pos max = {
        .x = m,
        .y = n
    };
    Pos end = {
        .x = m - 1,
        .y = n -1
    };

    int sum = dfs(cache, &start, &end, &max);

    return sum;
}
```