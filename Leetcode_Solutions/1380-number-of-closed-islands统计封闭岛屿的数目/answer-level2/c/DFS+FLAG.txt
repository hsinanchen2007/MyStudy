#define MIN_ROW_COL 3
unsigned int gridRow = 0;
unsigned int gridCol = 0;
/**
* DFS + FLAG  
* 外层记录岛屿个数
* 1、递归思想： 
      1、针对某个区域块来讲，深度优先查看这个点的 上下左右是否都是水域1，
      2、进一步用递归的思想就是对于每一个区域来说都是判断上下左右是否为 水域1
      3、退出条件 遍历到区域的边缘 任意边界没有水域 VAL为0，返回；
        周边存在水域直接返回，因为上边 边缘已经做了边界处理到了边界还没有水域VAL=0， 如果4边界 在没有到达边界都碰到了水域 VAL 是不会被置0
  2、DFS 深度优先
     1、判断当前区域后，接着沿着当前区域往下走
     2、对于已经走过的区域 用FLAG来标识，遍历过得节点 不需要重复遍历，岛屿内的 一次遍历一定是可以判断 是否封闭的。 
* 
* 
*/
void closedDfs(int** grid, int row, int col, unsigned int* val)
{
    if ((row >= gridRow) || (col >= gridCol)) {
        *val = 0;
        return;
    }
    
    if ((row < 0) || (col < 0)) {
        *val = 0;
        return;
    }

    if (grid[row][col] != 0) {
        return;
    }
    grid[row][col] = -1;
    closedDfs(grid, (row - 1), col, val);
    closedDfs(grid, (row + 1), col, val);
    closedDfs(grid, row, (col - 1), val);
    closedDfs(grid, row, (col + 1), val);
}

int closedIsland(int** grid, int gridSize, int* gridColSize)
{
    int row;
    int col;
    unsigned int val;
    unsigned int result = 0;
    if ((grid == NULL) || (gridColSize == NULL)) {
        return result;
    }
    if ((gridSize < MIN_ROW_COL) || (*gridColSize < MIN_ROW_COL)) {
        return result;
    }

    gridRow = gridSize;
    gridCol = *gridColSize;
    for (row = 1; row < (gridRow - 1); row++) {
        for (col = 1; col < (gridCol - 1); col++) {
            if (grid[row][col] == 0) {
                val = 1;
                closedDfs(grid, row, col, &val);
                result += val;
            }
        }
    }
    return result;
}