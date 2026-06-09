### 解题思路
看了大神们的讲解，总算是把这道题搞明白了，之前都没怎么用过二维数组，这个题用二维数组来记录方向真的让人眼前一亮
解题思路：
1.遍历数组，找到第一个为1的元素
2.对该元素打标，然后找它四个方位的元素，因为这里的操作都是一样的，可以使用递归
### 代码

```java
class Solution {
public int maxAreaOfIsland(int[][] grid) {
        //数组行
        int row = grid.length;
        //列
        int col = grid[0].length;

        //判断数组是否合规
        if (grid == null || row == 0 || col == 0) return 0;

        //定义数组元素是否被访问过,默认都是false
        boolean[][] visited = new boolean[row][col];

        //每次找到的岛屿面积
        int result = 0;

        //遍历数组
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {

                //若当前，该元素为1,标记为true,然后找前后左右是否为1
                //还要这个1是没访问过的
                if (grid[i][j] == 1 && !visited[i][j]) {
                    result = Math.max(result, dfs(grid, i, j, visited));
                }


            }


        }


        //遍历数组
        return result;
    }

    //定义方法dfs，记录每次遍历的结果
    private int dfs(int[][] grid, int i, int j, boolean[][] visited) {
        //将当前坐标，标记为已访问
        visited[i][j] = true;

        //构建一个二维数组，表示方向上 下 左 右
        int[][] dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

        int areas = 1;//岛屿面积
        int newRow;//新行坐标
        int newCol;//新列坐标
        //遍历节点的上下左右方向
        for (int[] dir : dirs) {
            //获取新坐标
            newRow = i + dir[0];
            newCol = j + dir[1];


            //若下一个元素是1，且没有被访问，就继续
            if (newRow < grid.length && newRow >= 0 && newCol < grid[0].length && newCol >= 0
                    && grid[newRow][newCol] == 1 && !visited[newRow][newCol]) {

                areas += dfs(grid, newRow, newCol, visited);

            }


        }


        return areas;


    }
}
```