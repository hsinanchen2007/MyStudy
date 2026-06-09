### 解题思路
1. 此题的关键是找到合适的状态转移方程。无论是对于递归合适动态规划方法。
2. 直接的想法就是戳破一个使当前状态获益最大的气球，然后将问题转化为子问题，继续戳。但是出现的问题是，这么做无法将问题转化为独立的重复子问题。因为戳破后的子问题的边界因戳不同的气球而不同。所以这个方法不奏效。
3. 关键的思想就是逆向思维，姑且这么说。我们现在不再找第一个戳破的气球，而是去找最后一个戳破的气球。也就是说，最后一个戳破的气球肯定只有一个，乘以两个1.然后去掉这个气球后得到的两个子问题，同样去找各自最后一个戳破的气球。这么一来，问题之间就独立了，也容易理清楚了。判出条件就是边界之间没有气球可以戳破。
4. 无论是递归还是动态规划，都基于上述思想。

### 代码

```java
class Solution {
    private int[][] dp;
    public int maxCoins(int[] nums) {
        if(nums == null || nums.length == 0) return 0;
        int[] nums2 = new int[nums.length+2];
        System.arraycopy(nums,0,nums2,1,nums.length);
        dp = new int[nums2.length][nums2.length];
        nums2[0] = 1;
        nums2[nums.length+1] = 1;
        return helper(nums2, 0, nums2.length-1);
    }

    private int helper(int[] nums2, int left, int right){
        if(right - left == 1) return 0;
        if(dp[left][right] != 0) return dp[left][right];
        int max = 0;
        for(int i = left + 1; i < right; i++){
            int tmp = helper(nums2, left, i) + helper(nums2, i, right) + nums2[left] * nums2[i] * nums2[right];
            if(max < tmp) max = tmp;
        }
        dp[left][right] = max;
        return max;
    }
}

class Solution {
    public int maxCoins(int[] nums) {
        if(nums == null || nums.length == 0) return 0;
        int[] nums2 = new int[nums.length + 2];
        System.arraycopy(nums, 0, nums2, 1, nums.length);
        int length = nums2.length;
        nums2[0] = 1;
        nums2[length-1] = 1;
        int[][] dp = new int[length][length];

        for(int i = length-3; i >= 0; i--)
            for(int j = i + 2; j < length; j++){
                int max = 0;
                for(int k = i + 1; k < j; k++){
                    int tmp = dp[i][k] + dp[k][j] + nums2[i] * nums2[k] * nums2[j];
                    if(max < tmp) max = tmp;
                }
                dp[i][j] = max;
            }
        
        return dp[0][length-1];
    }
}
```