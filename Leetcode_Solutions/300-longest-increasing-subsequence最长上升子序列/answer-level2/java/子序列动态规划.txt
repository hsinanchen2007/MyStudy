### 解题思路
分析题目 动态规划

### 代码

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        if(nums == null || nums.length == 0) return 0;
        int len = nums.length;

        int[] dp = new int[len];
        dp[0] = 1;

        for(int i=1;i<len;i++){

            int val = 0;
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j]){
                    val = Math.max(val,dp[j]);
                }
            }

            dp[i] = val +1;

        }

        int max = 0;
        for(int i=0;i<len;i++){
            max = Math.max(max,dp[i]);
        }

        return max;
    }
}
```