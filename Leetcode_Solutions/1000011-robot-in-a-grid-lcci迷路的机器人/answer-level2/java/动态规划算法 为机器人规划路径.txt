### 解题思路
![651a4355bb3ce6605fab7dea1c24bbb.png](https://pic.leetcode-cn.com/1ea4844eeff5e1a7682525d87294c9a36f3b640b38e253e9ee8c995d48e120cc-651a4355bb3ce6605fab7dea1c24bbb.png)

从二维数组的上看,想要移动到位置(x,y)位置的方式就是两种，一种是从其相邻位置,无非就是其上面(x-1,y),以及其左边(x,y-1)。 需要找到一条移动到(x,y-1)或者(x-1,y)的路径
以此类推要前往(x,y-1)或者(x-1,y) 需要找到其相邻的位置(x,y-1)的相邻位置为(x-1,y-1)和(x,y-2) 或者(x-1,y)的相邻位置为(x-2,y)和（x-1,y-1）
如果其中有一个方格不能通过，绕道而行。

### 代码

```java
class Solution {
   public List<List<Integer>> pathWithObstacles(int[][] obstacleGrid) {
        List<List<Integer>> paths=new ArrayList<>();
        if(obstacleGrid==null||obstacleGrid.length<1||obstacleGrid[0][0]==1) return paths;
        int r=obstacleGrid.length,c=obstacleGrid[0].length;
        /**
         *  visited数组 描述位置的三种状态
         *  0-未访问过,
         *  1-已访问过,但是不可通过,
         *  2-访问过并且可以通过
         */
        byte[][]visited = new byte[r][c];
        path(r-1, c-1, visited,obstacleGrid,paths);
        return paths;
    }

    /**
     * 判断当前位置是否可以通过
     * @param x
     * @param y
     * @param obstacles
     * @return
     */
    private boolean isPass(int x,int y,int[][]obstacles){

        if(x<0||x>=obstacles.length||y<0||y>=obstacles[0].length) return false;
        return obstacles[x][y]!=1;
    }

    public boolean path(int r,int c,byte[][]visited,int[][]obstacles,List<List<Integer>> paths){

        if(!isPass(r,c,obstacles)) return false;
        if(visited[r][c]!=0){
            return visited[r][c]!=1;
        }
        boolean success=false;
        if(r==0&&c==0) success=true;
        if(!success&&r>=1&&isPass(r-1,c,obstacles)){
            success = path(r - 1, c, visited, obstacles,paths);
        }
        if(!success&&c>=1&&isPass(r,c-1,obstacles)){
            success = path(r, c - 1, visited, obstacles,paths);
        }
        if(success){
            paths.add(Arrays.asList(r, c));
        }
        visited[r][c]=(byte)(success?2:1);
        return success;
    }
}
```