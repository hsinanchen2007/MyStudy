### 解题思路
![image.png](https://pic.leetcode-cn.com/fc4bd51d9c34e90b03f3e7a7bc656f6a19cc4f49dbd1d9727fc9a8377d8979b2-image.png)

逐个遍历二维数组元素，如果发现该元素为1，则分别从其上下左右四个方面蔓延，求得该区域的面积，同时将计算后的节点至为0，最后求得最大面积。


### 代码

```java
class Solution {
    int row;
    int column;
    int[][] local;
    int max = 0;
    public int maxAreaOfIsland(int[][] grid) {
        row = grid.length;
        column = grid[0].length;
        int res = 0;
        local = grid;
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                max = 0;
                if(grid[i][j] == 1){
                    bfs(i,j);
                    res = res>max?res:max;
                }
            }
        }
        return res;
    }
    public void bfs(int r,int c){
        if(r<0 || r>=row || c<0 || c>=column || local[r][c] == 0){
            return;
        }
        local[r][c] = 0;
        max++;
        bfs(r-1,c);
        bfs(r+1,c);
        bfs(r,c-1);
        bfs(r,c+1);
    }
}
```