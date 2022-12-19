### 解题思路
这道题用递归算法发现超时了，改用的动态规划。
公式是grid[i][j]=grid[i][j]+Math.max(grid[i-1][j],grid[i][j-1]);

### 代码

```java
class Solution {
    public int maxValue(int[][] grid) {
        for (int i=0;i<grid.length;i++){
            for (int j=0;j<grid[0].length;j++){
                if (i==0 && j==0)
                    continue;
                else if (i==0)
                    grid[i][j]=grid[i][j]+grid[i][j-1];
                else if (j==0)
                    grid[i][j]=grid[i][j]+grid[i-1][j];
                else{
                    grid[i][j]=grid[i][j]+Math.max(grid[i-1][j],grid[i][j-1]);
                }
            }
        }
        return grid[grid.length-1][grid[0].length-1];
    }
}
```
```java
class Solution {
   private int max=0;
   public int maxValue(int[][] grid) {
       helper(grid,0,0,0);
       return max;
   }
   private void helper(int[][] grid,int x,int y,int sum){
       if (x==grid[0].length)
           return;
       if (y==grid.length)
           return;
       if (x==grid[0].length-1 && y==grid.length-1){
           max=Math.max(max,sum+grid[y][x]);
           return;
       }
       helper(grid,x+1,y,sum+grid[y][x]);
       helper(grid,x,y+1,sum+grid[y][x]);
   }
}