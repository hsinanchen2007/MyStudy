### 解题思路
调试的时候先输出看看参数的内容，然后再写处理流程。注意判断搜索时的边界条件。
执行用时 : 12 ms, 在所有 C 提交中击败了 99.89% 的用户
内存消耗 : 6.3 MB, 在所有 C 提交中击败了100.00%的用户

### 代码

```c
int printGrid(int** grid, int gridSize, int* gridColSize){
    for(int i = 0 ; i < gridSize ; i++){
        printf("%d\n", gridColSize[i]);
    }
    for(int i = 0 ; i < gridSize ; i++ ){
        for(int j = 0 ; j < gridColSize[i] ; j++ ){
            printf("%d\t", grid[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------\n");
}
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int max = 0;
    // printGrid(grid, gridSize, gridColSize);
    for(int i = 0 ; i < gridSize ; i++ ){
        for(int j = 0 ; j < gridColSize[i] ; j++ ){
            if( grid[i][j] == 1 ){
                int cnt = dfs(grid, gridSize, gridColSize, i, j) ;
                if( max < cnt ){
                    max = cnt;
                }
            }
        }
    }
    // printf("%d\n", max);
    return max;
}

int dfs(int** a, int n, int* m ,int x, int y ){
    // printf("m[%d]=%d ", x, m[x]);
    // 边界值判断和以前的不同，弄了好久才发现是这儿的问题orz
    if( x < 0 || y < 0 || x >= n || y >= m[x] || a[x][y] == 0 ) return 0;
    int count = 0;
    if( a[x][y] == 1 ){
        a[x][y] = 0; // 标记已访问
        count++;
        // printf("*");
        count += dfs( a, n, m , x, y+1 );//右
        count += dfs( a, n, m , x, y-1 );//左
        count += dfs( a, n, m , x-1, y );//上
        count += dfs( a, n, m , x+1, y );//下
    }
    return count;
}

```