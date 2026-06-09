![奇怪的知识增加了.jpg](https://pic.leetcode-cn.com/1e05e2dcc17de90ae7710e7e8deef6dabb6eb284267e40e05fec73457fc46e38-%E5%A5%87%E6%80%AA%E7%9A%84%E7%9F%A5%E8%AF%86%E5%A2%9E%E5%8A%A0%E4%BA%86.jpg)

dp[i]代表包含nums[i]的最大上升子序列的长度。遍历它之前的数nums[j]，比他小，找到最大的dp[j]，然后加一就得到了dp[i]，最终结果是最大的dp[x]

### 代码

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        if(nums.length == 0) return 0;
        int maxLen = 1;
        int[] dp = new int[nums.length];
        dp[0] = 1;
        for(int i = 1; i<nums.length; i++){
            int tmp = 0;
            for(int j = i-1; j>=0; j--){
                if(nums[j]<nums[i] && dp[j] > tmp){
                    tmp = dp[j];
                }
            }
            dp[i] = 1 + tmp;
            maxLen = Math.max(dp[i], maxLen);
        }
        return maxLen;
    }
}
```