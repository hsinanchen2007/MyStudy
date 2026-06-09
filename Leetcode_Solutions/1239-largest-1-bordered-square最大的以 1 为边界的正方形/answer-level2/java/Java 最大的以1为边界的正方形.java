### 解题思路
其实就是四方向的Java版

时间复杂度$O(n^2)$
空间复杂度$O(n^2)$

### 代码

```java
class Solution {
    public int largest1BorderedSquare(int[][] grid) {
        int ans=0;
        int[][] dp_up=new int[grid.length][grid[0].length];
        int[][] dp_down=new int[grid.length][grid[0].length];
        int[][] dp_right=new int[grid.length][grid[0].length];
        int[][] dp_left=new int[grid.length][grid[0].length];
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                if(i==0) dp_up[i][j]=grid[i][j];
                else dp_up[i][j]=grid[i][j]==1?dp_up[i-1][j]+1:0;
            }
        }
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                if(j==0) dp_left[i][j]=grid[i][j];
                else dp_left[i][j]=grid[i][j]==1?dp_left[i][j-1]+1:0;
            }
        }
        for(int i=grid.length-1;i>=0;i--){
            for(int j=grid[0].length-1;j>=0;j--){
                if(i==grid.length-1) dp_down[i][j]=grid[i][j];
                else dp_down[i][j]=grid[i][j]==1?dp_down[i+1][j]+1:0;
            }
        }
        for(int i=grid.length-1;i>=0;i--){
            for(int j=grid[0].length-1;j>=0;j--){
                if(j==grid[0].length-1) dp_right[i][j]=grid[i][j];
                else dp_right[i][j]=grid[i][j]==1?dp_right[i][j+1]+1:0;
            }
        }

        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                int Long=1;
                while(i+Long-1<grid.length&&j+Long-1<grid[0].length){
                    if(grid[i+Long-1][j+Long-1]==1&&dp_up[i+Long-1][j+Long-1]>=Long&&dp_left[i+Long-1][j+Long-1]>=Long&&dp_down[i][j]>=Long&&dp_right[i][j]>=Long) ans=Math.max(ans,Long);
                    Long++;
                }
            }
        }
        return ans*ans;
    }
}
```