### 解题思路
动态规划。
想象成一棵树，从下向上思考。
递推公式：
dp[i][j] = Math.min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle.get(i).get(j);

### 代码

```java
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        if (triangle == null || triangle.size() == 0) {
            return 0;
        }
        
        int rows = triangle.size();
        int cols = triangle.get(rows - 1).size();

        int[][] dp = new int[rows][cols];
        for (int i = 0; i < cols; i++) {
            dp[rows - 1][i] = triangle.get(rows - 1).get(i);
        }

        for (int i = rows - 2; i >= 0; i--) {
            for(int j = 0; j <= i; j++) {
                dp[i][j] = Math.min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle.get(i).get(j);
            }
        }

        return dp[0][0];
    }
}
```