做本题之前，建议先做 200题和695题，然后再做本题，**本题是前两个的一个延伸**。

基本思路：
1. 使用 DFS 求得每一个独立小岛（**第200题的要求**），然后对于每一个小岛都编上一个号（index > 1），然后使用一个数组Area来记录每一个编号的小岛的面积(**类似于第695题的要求**)。

> 因为0代表海洋，1代表陆地，我们不能选择 0 和 1，那么我们就从 2 开始编号，也便于我们开辟一个数组来记录每一个编号的小岛的面积 

2. 然后对于每一个海洋（为0的地方），都查看其四周紧挨着的陆地，找到编号不同的陆地，将它们的面积相加(还要再加1，这块儿要改变的海洋的面积)，获得最大的面积即可。

具体代码和注释如下：

这是我的[LeetCode分类题解](https://github.com/caipengbo/LeetCode)（每日更新, issue内有总结），和我一起每日刷题吧！

```Java 
private int curIslandArea;
public int largestIsland(int[][] grid) {
    // 1 <= grid.length = grid[0].length <= 50
    int m = grid.length, n = grid[0].length;
    int[] area = new int[250];
    int index = 2, maxIslandArea = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            curIslandArea = 0;
            dfs(grid, i, j, index);
            if (curIslandArea != 0) {
                // 岛屿的最大面积
                maxIslandArea = Math.max(maxIslandArea, curIslandArea);
                // 记录每一块岛屿的面积
                area[index++] = curIslandArea;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0) {
                maxIslandArea = Math.max(maxIslandArea, changeSea(grid, m, n, area, i, j));
            }
        }
    }
    return maxIslandArea;
}
// DFS 求每一个小岛，并且获得每一个小岛的面积
private void dfs(int[][] grid, int i, int j, int index) {
    int m = grid.length, n = grid[0].length;
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) return;
    grid[i][j] = index;
    curIslandArea++;
    // 在此处判断，不用进入下一层递归
    dfs(grid, i-1, j, index);
    dfs(grid, i+1, j, index);
    dfs(grid, i, j-1, index);
    dfs(grid, i, j+1, index);
}
// 尝试改变每一个海洋(为0的地方)
private int changeSea(int[][] grid, int m, int n, int[] area, int i, int j) {
    Set<Integer> set = new HashSet<>();
    int areaSum = 1;
    if (i-1 >= 0) set.add(grid[i-1][j]);
    if (i+1 < m) set.add(grid[i+1][j]);
    if (j-1 >= 0) set.add(grid[i][j-1]);
    if (j+1 < n) set.add(grid[i][j+1]);
    for (Integer index : set) {
        areaSum += area[index];
    }
    return areaSum;
}
```