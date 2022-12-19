```
#include <stdbool.h>

static inline bool can_walk(int row, int col, int k);
static int union_find(int set[], int node);
static inline void union_join(int set[], int a, int b);
int movingCount(int m, int n, int k)
{
    if (n == 0 || m == 0)
        return 0;
    if (k == 0)
        return 1;

    int set[m * n];
    for (int i = 0; i < m * n; i++)
        set[i] = i;
    
    bool map[m][n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            map[i][j] = can_walk(i, j, k);
    
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!map[i][j])
                continue;
            if (i > 0 && map[i - 1][j])
                union_join(set, i * n + j, i * n + j - n);
            else if (j > 0 && map[i][j - 1])
                union_join(set, i * n + j, i * n + j - 1);
            cnt += (union_find(set, i * n + j) == 0) ? 1 : 0;
        }
    }

    return cnt;
}

static inline int get_sum(int num)
{
    int sum = 0;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

static inline bool can_walk(int row, int col, int k)
{
    return (get_sum(row) + get_sum(col)) <= k;
}

static int union_find(int set[], int node)
{
    if (set[node] == node)
        return node;
    return set[node] = union_find(set, set[node]);
}

static inline void union_join(int set[], int a, int b)
{
    int a_root = union_find(set, a);
    int b_root = union_find(set, b);
    if (a_root == b_root)
        return;
    set[a_root] = b_root;
}
```
