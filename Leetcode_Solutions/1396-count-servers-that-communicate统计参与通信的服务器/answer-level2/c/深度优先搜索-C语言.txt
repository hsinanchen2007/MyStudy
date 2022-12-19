```
/*
1、深度优先搜索，遍历所有连接行和列；
2、如果最终大于1 是有效的连接；
3、如果等于1，是无效的网络不需要统计。
*/

void dfs(int** grid, int gridSize, int* gridColSize,int row, int col,int *num)
{
    if (grid[row][col] == 0) {
        return;
    }
    grid[row][col] = 0;//将1连接颜色去掉，防止重复访问
    *num = *num + 1;

    //遍历行
    for (int i = 0; i < gridSize; i++) {
        if (grid[i][col] == 1) {
            dfs(grid, gridSize,gridColSize,i,col,num);
        }
    }
    //遍历列
    for (int j = 0; j < gridColSize[row]; j++) {
        if (grid[row][j] == 1) {
            dfs(grid, gridSize,gridColSize,row,j,num);
        }
    }

    return;
}


int countServers(int** grid, int gridSize, int* gridColSize) {
    int max = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if(grid[i][j] == 1) {
                int num = 0;
                dfs(grid, gridSize,gridColSize,i,j,&num);
                //如果等于1 说明是孤立节点1，不需要统计
                if (num > 1) {
                    max += num;
                }
            }
        }
    }

    return max;
}
```
