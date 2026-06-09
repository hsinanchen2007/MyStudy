
1、dp[i] 表示窗口左侧在原数组索引i所在位置时，对应最大值所在的所以，比如dp[0] = 1,因为【1，3，-1】最大值3所在索引为1；dp[1] = 1,因为【3，-1，-3】最大值3所在索引为1；dp[2] = 4,因为【-1，-3，5】最大值5所在索引为4
2、状态转移方程：当窗口最右边新进来的值大于等于上一个窗口最大值(nums[dp[i-1]])时,dp[j]就是此时窗口最右侧索引;dp[j] =  j + k - 1;当窗口最右边新进来的值小于上一个窗口最大值，看次最大值是否是原来的窗口最左侧，如果不是则dp[j] = dp[j-1];如果是则重新遍历k个元素最大值，记录索引。

class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if(nums == null || nums.length == 0 || k == 1) return nums;
        int dp[] = new int[nums.length - k + 1];
        dp[0] = 0;
        int res[] = new int[nums.length - k + 1];
        for(int i = 1; i < k; i++) {
            if(nums[i] >= nums[dp[0]]) dp[0] = i;
        }
        res[0] = nums[dp[0]];
        for(int j = 1; j < dp.length; j++) {
            if(nums[j + k - 1] >= nums[dp[j - 1]]) {
                dp[j] = j + k - 1;
            } else {
                if(dp[ j-1 ] == j - 1) {
                    dp[j] = j;
                    for(int q = j + 1; q < k + j; q++) {
                        if(nums[q] >= nums[dp[j]]) dp[j] = q;
                    }
                } else {
                    dp[j] = dp[j-1];
                }
            }
            res[j] = nums[dp[j]];
        }
        return  res;
    }
}
```