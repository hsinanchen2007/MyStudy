**我的[leetcode解题集](https://github.com/JuiceZhou/Leetcode)，求小星星呀(๑•̀ㅂ•́)و✧**


思路：

`dp[i][j]`表示从`nums[i]`到`nums[j]`先手比另一位玩家多的最大分数，最后返回`dp[0][nums.length-1]`是否大于0即可
 * 对于`dp[i][j]`，如果先手拿了`nums[i]`，则另一位玩家比先手多`dp[i+1][j]`，d`p[i][j] = nums[i]-dp[i+1][j]`，如果先手拿了`nums[j]`，则另一位玩家比先手多`dp[i][j-1]`，`dp[i][j] = nums[j]-dp[i][j-1]`
 * 综上，`dp[i][j] = Math.max(nums[i]-dp[i+1][j],nums[j]-dp[i][j-1])`
 * 当`i=j`时，先手一定赢，比另一位玩家多`dp[i][j]=nums[i]`

```
class Solution {
    public boolean PredictTheWinner(int[] nums) {
        int n = nums.length;
        int[][] dp = new int[n][n];
        //初始化
        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
        }
        //DP
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = Math.max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] >= 0;
    }
}
```
