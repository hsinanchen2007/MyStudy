# 说明
此题基于[300题：最长上升子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/)，在其基础上添加记录[0...i]包含当前元素i的最长递增子序列的个数
# 思路——动态规划
1. dp[len] 每遍历到一个元素，记录包含当前元素的最长递增子序列的长度
2. ct[len] 记录当前元素最长子序列长度的个数
3. 对于某个元素i,遍历[0...i-1]的所有dp元素值，并记录当前最大长度，
4. 遍历到的nums[j]>nums[i]的前提下：
    - 若当前长度+1大于记录的最大长度，将计数置为当前元素记录个数，并更新最大长度
    - 若等于，计数加上当前记录个数；
    - 若小于，不计。
# 代码
```
public int findNumberOfLIS(int[] nums) {
    int count = 0;
    int len = nums.length, max_len = 0;
    int[] dp = new int[len];
    int[] ct = new int[len];
    for (int i = 0; i < len; i++) {
        dp[i] = 1;
        ct[i] = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (nums[i] <= nums[j] || dp[j] + 1 < dp[i])
                continue;
            if (dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                ct[i] = ct[j];
            } else {
                // nums[i]>nums[j] && dp[j] + 1 == dp[i]的情况累加子序列个数
                ct[i] += ct[j];
            }
        }
        if (dp[i] == max_len) {
            count += ct[i];
        }
        // 出现更长的子序列，更新计数值和最长子序列长度
        if (dp[i] > max_len) {
            count = ct[i];
            max_len = dp[i];
        }
    }
    <!-- System.out.println(Arrays.toString(ct)); -->
    <!-- System.out.println(Arrays.toString(dp)); -->
    return count;
}
```
# 总结
1. 核心思想：不管是dp[i]还是ct[i]，数组所记录的最长子序列长度或个数，都以必须包含当前元素nums[i]为前提，就比较好分析.
2. 时间复杂度O(n^2),空间复杂度O(n).