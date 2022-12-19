### 解题思路
既然数学功底不好，很难找规律，那就暴利解法吧

### 代码

```java
class Solution {
    public int countNegatives(int[][] grid) {
        //m*n是m行n列
        int m=grid.length;
        int n=grid[0].length;
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]<0)
                {
                    count+=n-j;break;
                }
            }
        }
        return count;
    }
}
```