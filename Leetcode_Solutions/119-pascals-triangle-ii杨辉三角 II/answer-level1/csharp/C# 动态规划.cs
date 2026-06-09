### 解题思路
与[118](https://leetcode-cn.com/problems/pascals-triangle/solution/c-dong-tai-gui-hua-by-imopika/)思路一样。

### 代码

```csharp
public class Solution {
    public IList<int> GetRow(int rowIndex) {
        int numRows = 34;
        int[][] dp =new int[numRows][];
        for(int i = 0;i<numRows;i++)
        {
            dp[i] = new int[i+1];
            for(int j = 0;j<=i;j++)
            {
                if(j==0 || j ==i)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
            }
        }

        return dp[rowIndex].ToList();
    }
}
```