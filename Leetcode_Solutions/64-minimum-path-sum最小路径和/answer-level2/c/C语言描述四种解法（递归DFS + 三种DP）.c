# 解法1
## 思路
穷举所有可能，DFS（深度优先搜索），超时了！
## 逻辑
找最小，那最朴素的想法就是要遍历所有可能的值。这种每步操作相似（要么往右，要么往下）、需完成深度搜索、靠回溯穷举的问题，直观的思维就是DFS的递归实现。但是时间复杂度不符合LeetCode的OJ要求，写出来只是提供一个思路参考。过程描述详见代码注释。
## 复杂度
时间复杂度：O(2^{m + n})。每次可以往两个方向移动，横向移动m次，纵向移动n次。
空间复杂度：O(m + n)。递归的深度是（行长 + 列长）。
```
// Solution 1: DFS recursively
// i: 现在到哪一行了（取值范围是列的长度）
// j: 现在到哪一列了（取值范围是行的长度）
int dfs(int** grid, int j, int i, int cur, int min, int rowLength, int columnLength) {
    // 没走到一个格子内，要加上这个格子的值，即经过此格子，路程要加多少
    cur += grid[i][j];
    // 递归返回条件：走到最后（最右下角）一个格子的时候
    if (j == rowLength - 1 && i == columnLength - 1) {
        // 如果min = -1（第一次走到最后一个格子），把当前次的路程的和（cur）赋值给min
        // 或
        // 其他次走到最后一个格子，把当前次的路程和（cur）与之前的min比较，如果比min小，则赋值给min
        min = (min == -1 || cur < min) ? cur : min;
        // 返回最小值
        return min;
    }
    // 如果没到最后一列，就继续往右面格子递归
    if (j < rowLength - 1) min = dfs(grid, j + 1, i, cur, min, rowLength, columnLength);
    // 如果没到最后一行，就继续往下面格子递归
    if (i < columnLength - 1) min = dfs(grid, j, i + 1, cur, min, rowLength, columnLength);
    return min;
}

int minPathSum(int** grid, int gridSize, int* gridColSize){
    // 记录当前值
    int cur = 0;
    // 记录全局最小值
    int min = -1;
    // 以递归形式进行DFS搜索
    return dfs(grid, 0, 0, cur, min, *gridColSize, gridSize);
}
```

# 解法2
## 思路
动态规划 + 二维数组记录每一步的解
## 逻辑
创建二维数组dp[行数][列数]，dp[i][j]值的含义是格子grid[i][j]到右下角格子最近的距离值。
## 状态转移方程 
- 如果是最后一行格子，dp[i][j] = grid[i][j] + dp[i][j + 1]（当前点的值+右侧的值）
- 如果是最后一列格子，dp[i][j] = grid[i][j] + dp[i + 1][j]（当前点的值+下面的值）
- 如果是中间格子，d[i][j] = grid[i][j] + min(dp[i][j + 1], dp[i + 1][j])（当前点的值+min(右侧的值, 下面的值)）
- 如果是最右下角格子，d[i][j] = grid[i][j]（就等于最下角格子的值）
## 复杂度
时间复杂度：O(mn)。遍历了一遍m * n阶的二维数组。
空间复杂度：O(n)。申请大小等于原始数组二维数组额外存储空间。
```
#define min(a, b) (a < b ? a : b)
int minPathSum(int** grid, int gridSize, int* gridColSize){
    int columnLength = gridSize;
    int rowLength = *gridColSize;
    int dp[columnLength][rowLength];
    for (int i = columnLength - 1; i >= 0; i--)
        for (int j = rowLength - 1; j >= 0; j--) {
            if (i == columnLength - 1 && j != rowLength - 1) dp[i][j] = grid[i][j] + dp[i][j + 1];
            else if (i != columnLength - 1 && j == rowLength - 1) dp[i][j] = grid[i][j] + dp[i + 1][j];
            else if (i != columnLength - 1 && j != rowLength - 1) dp[i][j] = grid[i][j] + min(dp[i][j + 1], dp[i + 1][j]);
            else dp[i][j] = dp[i][j];
        }
    return **dp;
}
```

# 解法3
## 思路
动态规划 + 一维数组记录每一步的解
## 逻辑
创建二维数组dp[列数]
等式左侧的dp[j]的值，含义是当前格子grid[i][j]到右下角格子最近的距离值。
等式右侧的dp[j]的值，含义是当前格子grid[i][j]下面那个格子的值，即前一次i循环时（前一行）的同一列的值
等式右侧的dp[j + 1]的值，含义是当前格子grid[i][j]右侧那个格子的值，即当前次i循环时（当前行）的右侧一列的值
个人觉得这里不太好想，很多解答也没有详细描述，所以特意多磨叽一下，当然还是很拗口，不好懂，这里费劲的人（包括本人）还是尽量多想想多练练吧。
## 状态转移方程 
- 如果是最后一行，dp[j] = grid[i][j] + dp[j + 1]（当前格子的值+当前列（j）右侧（+1）的值）
- 如果是最后一列，dp[j] = grid[i][j] + dp[j]（当前格子的值+当前列（j）下面（之前一次循环的i）的值）
- 如果是中间，d[i][j] = grid[i][j] + min(dp[j + 1], dp[j])（当前格子的值+min(当前格子右侧的值, 当前格子下面的值)）
- 如果是最右下角，d[i][j] = grid[i][j]（就等于最下角的值）
## 复杂度
时间复杂度：O(mn)。遍历了一遍m * n阶的二维数组。
空间复杂度：O(n)。申请大小为列数（行长度）的一维数组额外存储空间。
```
#define min(a, b) (a < b ? a : b)
int minPathSum(int** grid, int gridSize, int* gridColSize) {
    int columnLength = gridSize;
    int rowLength = *gridColSize;
    int dp[rowLength];
    for (int i = columnLength - 1; i >= 0; i--)
        for (int j = rowLength - 1; j >= 0; j--) {
            if (i == columnLength - 1 && j != rowLength - 1) dp[j] = grid[i][j] + dp[j + 1];
            else if (i != columnLength - 1 && j == rowLength - 1) dp[j] = grid[i][j] + dp[j];
            else if (i != columnLength - 1 && j != rowLength - 1) dp[j] = grid[i][j] + min(dp[j], dp[j + 1]);
            else dp[j] = grid[i][j];
        }
    return *dp;
```

# 解法4
## 思路
动态规划 + 用原始二维数组grid记录
## 逻辑
原理同Solution 2，只不过没建立二位dp数组，而是用grid本身去存储。即每遍历一个格子grid[i][j]，就用之前方法计算出dp[i][j]的值去覆盖grid[i][j]。遍历结束后，二维数组grid就变成了之前的二维数组dp。
## 复杂度
时间复杂度：O(mn)。遍历了一遍m * n阶的二维数组。
空间复杂度：O(1)。无申请额外存储空间。
```
#define min(a, b) (a < b ? a : b)
int minPathSum(int** grid, int gridSize, int* gridColSize) {
    int columnLength = gridSize;
    int rowLength = *gridColSize;
    for (int i = columnLength - 1; i >= 0; i--)
        for (int j = rowLength - 1; j >= 0; j--) {
            if (i == columnLength - 1 && j != rowLength - 1) grid[i][j] = grid[i][j] + grid[i][j + 1];
            else if (i != columnLength - 1 && j == rowLength - 1) grid[i][j] = grid[i][j] + grid[i + 1][j];
            else if (i != columnLength - 1 && j != rowLength - 1) grid[i][j] = grid[i][j] + min(grid[i][j + 1], grid[i + 1][j]);
            else grid[i][j] = grid[i][j];
        }
        return **grid;
}
```
