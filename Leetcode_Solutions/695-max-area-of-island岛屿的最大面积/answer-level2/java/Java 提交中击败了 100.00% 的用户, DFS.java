### 解题思路
使用深度搜索的思想，分成两重循环+深搜两个模块来写代码。
1.两重for循环:
（1）简单的整体遍历一遍，寻找值为1的点；
（2）找到一个就进去深度搜索寻找周边点形成的面积并返回；
（3）同时与当前最大面积`area`进行比较，进行赋值；
（4）遍历完所有的点结束。
2.深搜：
（1）判断当前点是否在数组范围内, 当前点是否满足值为1的条件；
（2）对值为1的点进行赋0，表示已经访问过了；
（3）对该点进行上下左右的递归；

### 代码

```java
class Solution {

    int row = 0, col = 0, area = 0;
    public int maxAreaOfIsland(int[][] grid) {

        row = grid.length;
        col = grid[0].length;
        for(int i = 0; i < row; i++){
            for(int j =  0; j < col; j++){
                if(grid[i][j] == 1){ 
                    int s = dfs(grid, i, j);
                    if(s > area){
                        area = s;
                    }
                }
            }
        }
        return area;

    }

    private int dfs(int[][] grid, int i, int j){
        if(i < 0 || i >= row || j < 0 || j >=col || grid[i][j] == 0){
            return 0;
        }
        grid[i][j] = 0;
        
        return dfs(grid, i+1, j) +
        dfs(grid, i-1, j ) +
        dfs(grid, i, j+1) +
        dfs(grid, i, j-1) + 1; 
    }
}
```