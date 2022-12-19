floodfill算法：在二维平面上进行遍历，实质就是深度优先遍历,但是要标记遍历过的点。

解题技巧：
- 使用一个helper二维数组，模拟节点的上下左右的移动；
- 需要有一个函数，判断进行移动操作后，坐标还在不在数组内
- 需要有一个数组visited，来标记遍历后的节点（在本题中可以直接的将遍历过的点的数值变成0）

### 代码

```java
class Solution {
    // helper用来模拟点的上下左右移动
    int [][] helper = {{-1,0},{0,1},{1,0},{0,-1}};
    // 全局变量，用来进行数值的记录与判断
    int m;
    int n;
    int tempArea = 1;

    public int maxAreaOfIsland(int[][] grid) {
        m = grid.length;
        if(m == 0){
            return 0;
        }
        n = grid[0].length;
        int res = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 1){
                    // 找到一个岛屿，进行dfs遍历，tempArea记录本次遍历的岛的大小
                    dfs(grid,i,j);
                    // 该次遍历后，比较岛屿面积的大小，大的赋值给res
                    res = Math.max(res,tempArea);
                    // 初始化
                    tempArea = 1;
                }
            }
        }
        return res;
    }

    public void dfs(int[][] grid,int startX,int startY){
        // 标记已经使用的点
        grid[startX][startY] = 0;

        for(int i = 0;i < 4;i++){
            // 进行点的移动
            int newX = startX + helper[i][0];
            int newY = startY + helper[i][1];
            if(isIn(newX,newY) && grid[newX][newY] == 1){
                // 满足条件，岛屿面积 +1
                tempArea++;
                dfs(grid,newX,newY);
            }
        }
    }

    // 判断点在不在二维数组里
    public boolean isIn(int x,int y){
        if(x < m && x >= 0 && y >=0 && y < n){
            return true;
        }
        return false;
    }
}
```

# 一般解法
这种在二维平面上，点可以上下左右移动的题，一般都可以使用floodfill方法，在dsf的基础上，标记遍历过的点，一般使用二维数组来进行标记

下面是使用二维数组的解法，也可以认为是该类型题的一个模板
```java
class Solution {

    int [][] helper = {{-1,0},{0,1},{1,0},{0,-1}};
    int m;
    int n;
    // 来记录访问过的点
    boolean [][]visited;
    int tempArea = 1;

    public int maxAreaOfIsland(int[][] grid) {
        m = grid.length;
        if(m == 0){
            return 0;
        }
        n = grid[0].length;
        visited = new boolean[m][n];
        int res = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                // 满足条件 && 没被使用过 
                if(grid[i][j] == 1 && !visited[i][j]){
                    dfs(grid,i,j);
                    res = Math.max(res,tempArea);
                    tempArea = 1;
                }
            }
        }

        return res;
    }

    public void dfs(int[][] grid,int startX,int startY){
        visited[startX][startY] = true;
        // grid[startX][startY] = 0;
        for(int i = 0;i < 4;i++){
            int newX = startX + helper[i][0];
            int newY = startY + helper[i][1];
            // 满足条件 && 没被使用过 
            if(isIn(newX,newY) && grid[newX][newY] == 1 && !visited[newX][newY]){
                tempArea++;
                dfs(grid,newX,newY);
            }
        }
    }


    public boolean isIn(int x,int y){
        if(x < m && x >= 0 && y >=0 && y < n){
            return true;
        }
        return false;
    }
}
```
一道类似的题： [200. 岛屿数量](https://leetcode-cn.com/problems/number-of-islands/submissions/)
