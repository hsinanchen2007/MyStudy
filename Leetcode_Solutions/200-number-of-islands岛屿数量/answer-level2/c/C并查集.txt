### 解题思路
将相邻的'1'放入同一个集合，最后统计集合数即为岛屿数，用并查集实现。

### 代码

```c

struct union_find_set {
    uint64_t **parent; // bit32~bit63:row bit0~bit31:col
    int **rank;
};



uint64_t ufs_find(struct union_find_set *ufs, uint64_t n)
{
    int row = (n >> 32);
    int col = (n & 0xffffffff);

    if (ufs->parent[row][col] == n)
        return n;
    ufs->parent[row][col] = ufs_find(ufs, ufs->parent[row][col]);
    return ufs->parent[row][col];
}

void ufs_union(struct union_find_set *ufs, uint64_t m, uint64_t n)
{
    int row_m;
    int col_m;
    int row_n;
    int col_n;
    int rank_m;
    int rank_n;

    m = ufs_find(ufs, m);
    n = ufs_find(ufs, n);
    if (m == n)
        return;

    row_m = (m >> 32);
    col_m = (m & 0xffffffff);
    row_n = (n >> 32);
    col_n = (n & 0xffffffff);
    rank_m = ufs->rank[row_m][col_m];
    rank_n = ufs->rank[row_n][col_n];
    if (rank_m < rank_n) {
        ufs->parent[row_m][col_m] = n;
    } else {
        ufs->parent[row_n][col_n] = m;
        if (rank_m == rank_n)
            ufs->rank[row_m][col_m]++;
    }
}


int numIslands(char** grid, int gridSize, int* gridColSize){
    int row;
    int col;
    uint64_t i;
    int j;
    struct union_find_set ufs;
    int num = 0;

    if ((grid == NULL) || (gridSize == 0) || (gridColSize == NULL))
        return 0;

    row = gridSize;
    col = gridColSize[0];

    ufs.parent = (int **)malloc(sizeof(uint64_t *) * row);
    ufs.rank = (int **)malloc(sizeof(int *) * row);
    for (i = 0; i < row; i++) {
        ufs.parent[i] = (uint64_t *)malloc(sizeof(uint64_t) * col);
        ufs.rank[i] = (int *)malloc(sizeof(int) * col);
        for (j = 0; j < col; j++) {
            if (grid[i][j] == '1') {
                uint64_t m;
                uint64_t n;
                m = (i << 32) + j;
                ufs.parent[i][j] = m;
                ufs.rank[i][j] = 0;
                if (j > 0 && grid[i][j - 1] == '1') {
                    n = (i << 32) + (j - 1);
                    ufs_union(&ufs, n, m);
                }
                if (i > 0 && grid[i - 1][j] == '1') {
                    n = ((i - 1) << 32) + j;
                    ufs_union(&ufs, n, m);
                }
            } else {
                ufs.parent[i][j] = -1;
            }
        }
    }

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (ufs.parent[i][j] == ((i << 32) + j))
                num++;
        }
        free(ufs.parent[i]);
        free(ufs.rank[i]);
    }

    free(ufs.parent);
    free(ufs.rank);

    return num;
}
```