### 解题思路
可以使用深度优先遍历进行解决
    深度优先便利的模版
    /**
    参数n表示搜索到某一个节点，
    参数d表示到达的深度
    return 表示是否有解
    boolean DFS(Node n, int d){
        if(isEnd(n, d)){ // 一旦达到某一个节点满足 条件，就返回true
            return true;
        }    
        for(Node NextNode in n){
            visited[NextNode] = false; //在下一次搜索中，该节点不能再次出现
            if(DFS(NextNode, d+1)){//如果搜索出有解
                //做某种处理
                return true;
            }
            visited[NextNode] = true; //重新表示true，该节点有可能出现在下一次搜索的别的路径中
        }
        return false;//表示这次搜索无解
    }
    */

### 代码

```java
class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int res = 0;
        int area = 0;
        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[0].length; j++){
                if(grid[i][j] == 1){
                    area = getArea(grid,i , j);
                    res = res > area ? res : area;
                }
            }
        }
        return res;
    }
    public int getArea(int[][] grid, int i, int j){
        //递归的终止条件
        if(i == grid.length || i < 0){
            return 0;
        }
        if(j == grid[0].length || j < 0){
            return 0;
        }
        if(grid[i][j] == 1){
            grid[i][j] = 0;
            return 1 + getArea(grid, i - 1, j) + getArea(grid, i +1, j) + getArea(grid, i, j- 1)                                    +getArea(grid, i , j +1);
        }
        return 0;
    }
}
```