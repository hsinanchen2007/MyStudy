### 解题思路
看着官方的DFS解题思路写的个人理解：
关键点1.在于标记已经访问过的陆地点。
2.找到for循环中当前陆地点的周边所有相连的陆地。
3.确定每次查找的边界值。
DFS 算法还是有待加强理解和练习呀。

### 代码

```java
class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int result = 0;
        for (int i=0;i<grid.length;i++) {
            for (int j=0;j<grid[i].length;j++) {
                // 遍历每一个点 如果当前点为陆地则判断当前点的水平和垂直方向是否有陆地存在
                if (grid[i][j] == 1) {
                    // 使用DFS 遍历当前点周边的所有点是否存在陆地
                    result = Math.max(dfs(i,j,grid),result);
                }
            }
        }
        return result;
    }

    public int dfs(int i,int j,int[][] grid) {
        // 递归时做边界判断是否存在越界 或者当前点为水
        if (i<0 || j<0 || i>= grid.length || j>=grid[i].length || grid[i][j] == 0) {
            return 0;
        }
        // 将陆地标记为水 标识已经访问的陆地
        grid[i][j] = 0;
        int sum = 1;
        // 当前访问点 所有右边为陆地的个数
        sum += dfs(i+1,j,grid);
        // 当前访问点 所有左边为陆地的个数
        sum += dfs(i-1,j,grid);
        // 当前访问点 所有上边为陆地的个数
        sum += dfs(i,j-1,grid);
        // 当前访问点 所有下边为陆地的个数
        sum += dfs(i,j+1,grid);
        return sum;
    }
}
```