## 思路分析
- dp[i] 代表第 i 天最多可以预约多少时间
- 那状态转移分两种:
- 情况一, 当天如果出来接客,那就是前一天不能接客,状态从 i-2 开始转移 dp[i] = d[i-2] + nums[i]
- 情况二, 当天如果不接客,那就去前一天的,状态从 i-1 转移过来  dp[i] = dp[i-1]
- 所以两种情况比较下选择最优的

```
class Solution {
    public int massage(int[] nums) {
        if (nums.length == 0){
            return 0;
        }
        int len = nums.length;
        int[] dp = new int[len];
        dp[0] = nums[0];
        for(int i = 1; i < len ; i++){
            dp[i] = dp[i-1];
            int temp = 0;
            if (i-2>=0){
                temp = dp[i-2];
            }
            if (dp[i] < temp + nums[i]){
                dp[i] = temp + nums[i];
            }
        }
        return dp[len-1];
    }
}
```
