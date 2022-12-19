# DP
对于序列 10 9 2 5 3 7 101 18
依次求出10，10 9，10 9 2，...，10 9 2 5 3 7 101 18序列的最长上升子序列求最大值
dp[i]表示nums[0]...nums[i] 的最上上升子序列长度
*那么dp[i+1]怎么求呢？
求出nums[0]...nums[i]中小于nums[i+1]的所有元素
然后【小于nums[i+1]的所有元素】其中最大的上升子序列值+1即为dp[i+1]*
# 例子
10 9 2 5 3 7 101 18
dp数组为：
1. 1 1 1 1 1 1 1 1，i = 0时
2. 1 1 1 1 1 1 1 1，i = 1时
3. 1 1 1 1 1 1 1 1，i = 2时
4. 1 1 1 2 1 1 1 1，i = 3时
5. 1 1 1 2 2 1 1 1，i = 4时
6. 1 1 1 2 2 3 1 1，i = 5时
7. 1 1 1 2 2 3 4 1，i = 6时
8. 1 1 1 2 2 3 4 4，i = 7时

```Java
class Solution {
    public int lengthOfLIS(int[] nums) {
        if(nums.length <= 1){
            return nums.length;
        }
        int[] dp = new int[nums.length];
        for(int i = 0; i < nums.length; i++){
            dp[i] = 1;
        }
        int ans = 1;
        for(int i = 1; i < nums.length; i++){
            int maxDP = -1;
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    maxDP = Math.max(maxDP, dp[j]);
                }
            }
            if(maxDP != -1){
                dp[i] = maxDP + 1;
                ans = Math.max(ans, dp[i]);
            }
        }
        return ans;
    }
}
```
