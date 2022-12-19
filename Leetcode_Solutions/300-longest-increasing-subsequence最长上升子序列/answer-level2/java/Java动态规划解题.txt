### 解题思路
此处撰写解题思路
最长上升子序列和最长递增子序列是一个意思
对于数组中某个元素nums[i],nums[j],且 i < j,则 nums[j]对应的递增长度 = nums[i]对应的递增长度 + 1
状态转移方程式： dp[i] = Math.max(dp[i],dp[j] + 1); (nums[j] < nums[i]的情况下)
### 代码

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        if (nums.length < 1) return 0;
        int[] dp = new int[nums.length];
        Arrays.fill(dp,1);
        for(int i = 1; i < nums.length;i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = Math.max(dp[i],dp[j] + 1);
                }
            }
        }
        int max = Integer.MIN_VALUE;
        for(int num:dp){
            max = Math.max(max,num);
        }
        return max;
    }
}
```