### 解题思路
看到最优解问题我首先想到的就是动态规划，奈何动态规划做的题还是太少，这道题是在看了题解的情况下做了出来。
思路：
（1）递推式：dp[i] = max(dp[i - 1] + nums[i], nums[i])，dp[i]的意义是**以nums[i]为结尾**的子序列的和的最大值，那么这个递推式的意义是当之前累积的最大值是个负数时则以nums[i]为开始计算子序列。
（2）边界：dp[0] = nums[0]
做完这道题有个小小的体会：我曾经以为动态规划最后一个位置就是所要求的答案，但其实并不是，比如这道题，实际上答案是max(dp)。

### 代码

```python
class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        length = len(nums)
        dp = [0] * length
        max_num = dp[0] = nums[0]
        for i in range(1, length):
            dp[i] = max(dp[i - 1] + nums[i], nums[i])
            max_num = max(max_num, dp[i])
        return max_num
```