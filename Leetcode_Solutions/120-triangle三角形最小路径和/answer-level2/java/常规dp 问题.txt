### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int N = triangle.size();
        int [][] dp = new int [N][N];
        int k = 0;
        for (Integer t : triangle.get(N-1)) {
            dp[N-1][k++] = t;
        }
        for (int i = N-2; i >= 0; i--) {
            for (int j = 0; j <= i;j++) {
                dp[i][j] = triangle.get(i).get(j) + Math.min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
}
```