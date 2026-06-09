### 解题思路
方程：dp[i] = max{dp[i-1] + nums[i],nums[i]};
解释：dp[i] 为下标为i的最大值，如nums = [-2,1,-3,4,-1,2,1,-5,4]，dp[0]=-2即下标为0是的最大值。
递归方程的得到：下标为i的最大值是前面若干个(包括0个)连续数字最大值加上本数字的和，满足最优子结构。

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int[] max = new int[nums.length];
        max[0] = nums[0];
        int ans = max[0];
        for (int i = 1;i < nums.length;i++){
            max[i] = Math.max(max[i-1] + nums[i],nums[i]);
            ans = Math.max(ans,max[i]);
        }
        return ans;
    }
}
```