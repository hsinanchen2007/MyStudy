### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int minPathSum(int[][] grid) {
        int[] cur = new int[grid[0].length];
        cur[0] = grid[0][0];
        for(int i = 1; i<grid[0].length; i++)
            cur[i] = grid[0][i] + cur[i-1];
        for(int i = 1; i<grid.length; i++)
        {
            for(int j = 0; j<grid[0].length; j++)
            {
                if(j==0)
                {
                    cur[j] = cur[j]+grid[i][0];
                }
                else
                {
                    cur[j] = Math.min(cur[j-1], cur[j]) + grid[i][j];
                }
            }
        }
        return cur[grid[0].length-1];
    }
}
```