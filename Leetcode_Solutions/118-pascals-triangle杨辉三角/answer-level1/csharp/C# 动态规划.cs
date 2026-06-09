### 解题思路
使用动态规划

根据题目中给出的图形示例，我们需要定义一个 jagged(锯齿)数组，它的长度与 `numRows` 一样。

观察图例，不难看出，对于 i,j 这样两维访问变量，当 j=0 或 j=i 时，目标值都是 1，除此之外，目标值是 dp[i][j] = dp[i-1][j-1] + dp[i-1][j]。

### 代码

```csharp
public class Solution {
    public IList<IList<int>> Generate(int numRows) {
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

        IList<IList<int>> p = new List<IList<int>>();
        for(int i = 1;i<= numRows;i++)
        {
            var list = dp[i-1].ToList();
            p.Add(list);
        }
        
        return p;
    }
}
```