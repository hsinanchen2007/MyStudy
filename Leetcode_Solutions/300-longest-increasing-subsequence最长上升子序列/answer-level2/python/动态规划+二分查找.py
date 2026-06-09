# 300. 最长上升子序列

## 1. 题目描述

[最长上升子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/)

## 2. 解法

**方法1**：动态规划，时间复杂度O(n<sup>2</sup>)

dp[i]：以nums[i]为结尾的子数组的最长子序列的长度，初始化为1。

动态转移方程：


$$
dp[i] = max(dp[i], dp[j] + 1),其中0 <= j < i 以及 nums[j] > nums[j]
$$

```python
class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 动态规划O(n^2)
        # dp[i]：以i为结尾的最大上升字序列的长度,初始化为1
        # 转移方程：dp[i] = max(dp[i], dp[j] + 1) and 0 <= j < i and nums[i] > nums[j]
        if not nums: return 0
        n = len(nums)
        dp = [1 for _ in range(n)]
        res = 1
        for i in range(1, n):
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)
            res = max(res, dp[i])
        return res
```

**方法2**：二分查找时间复杂度O(nlogn).

贪心的思想：如果要找一个最长的上升的子序列，那么这个子序列的尾部元素应该尽量小，这样才有更大的可能为这个子序列添加新的元素。

对原序列进行遍历，将每位元素二分插入 dp数组中。

- 如果 dp 中元素都比它小，将它插到最后
- 否则，用它覆盖掉比它大的元素中最小的那个

```python
class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:return 0
        dp = [nums[0]]
        for i in range(1, len(nums)):
            if nums[i] > dp[-1]:
                dp.append(nums[i])
            else: # 二分查找，找合适的位置插入，也就是找替换比当前数大的最小的那个数
                left, right = 0, len(dp) - 1
                while left <= right:
                    mid = left + (right - left) // 2
                    if dp[mid] < nums[i]:
                        left = mid + 1
                    elif dp[mid] >= nums[i]:
                        right = mid - 1
                dp[left] = nums[i]
        return len(dp)
```

