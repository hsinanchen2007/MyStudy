### 解题思路
此处撰写解题思路
递推公式：dp[i][j] = dp[i - 1][j - nums[i]] + dp[i - 1][j + nums[i]];
和（从最小到最大）:  
-5  -4  -3  -2  -1   0   1   2   3   4   5
dp数组：  
      0   0   0   0   1   0   1   0   0   0   0
      0   0   0   1   0   2   0   1   0   0   0
      0   0   1   0   3   0   3   0   1   0   0
      0   1   0   4   0   6   0   4   0   1   0
      1   0   5   0   10  0   10  0   5   0   1
初始化注意：nums[0]等于0时，dp[0][sum]=2（因为+-0都是0），其他情况遵循递推公式（等于它临近左上肩和右上肩元素之和）。

### 代码

```java
class Solution {
    public int findTargetSumWays(int[] nums, int s) {
        int sum = 0;//保存所有元素之和
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
        }
        // 绝对值范围超过了sum的绝对值范围则无法得到
        if (Math.abs(s) > Math.abs(sum)) 
        return 0;
        int len = nums.length;
        // - 0 + 每个元素要么前面添加-、要么+、要么不被选中
        int t = sum * 2 + 1;
        int[][] dp = new int[len][t];
        // 初始化
        if (nums[0] == 0) {
            dp[0][sum] = 2;
        } else {
            dp[0][sum + nums[0]] = 1;
            dp[0][sum - nums[0]] = 1;
        }
        for (int i = 1; i < len; i++) {
            for (int j = 0; j < t; j++) {
                // 边界
                int l = (j - nums[i]) >= 0 ? j - nums[i] : 0;
                int r = (j + nums[i]) < t ? j + nums[i] : 0;
                dp[i][j] = dp[i - 1][l] + dp[i - 1][r];
            }
        }
        return dp[len - 1][sum + s];
    }
}
```