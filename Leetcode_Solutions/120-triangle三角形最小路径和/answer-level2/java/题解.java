### 解题思路
这道题很好的体现了动态规划自顶向下和自底向上两种思路，我采用了自底向下，不需要考虑边界情况

### 代码

```java
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int row = triangle.size();
        int column = triangle.get(triangle.size() - 1).size();
        int[][] dp = new int[row][column];

        for (int i = row - 1; i >= 0; i--) {
            for (int j = 0; j < i + 1; j++) {
                if (i == row - 1) {
                    dp[row - 1][j] = triangle.get(row - 1).get(j);
                    continue;
                }
                dp[i][j] = Math.min(dp[i + 1][j], dp[i + 1][j +1]) + triangle.get(i).get(j);
            }
        }
        return dp[0][0];
    }
}
```