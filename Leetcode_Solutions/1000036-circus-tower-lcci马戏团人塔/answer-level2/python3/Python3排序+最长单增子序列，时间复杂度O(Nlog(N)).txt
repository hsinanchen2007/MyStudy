## 解题思路
1. 将所有元素按照`height`从小到大，`weight`从大到小排序
2. 在排好序的数组中，求按`weight`严格单调递增的最长严格单调递增子序列的长度

## 时间复杂度
排序`O(nlog(n))` + 求最长单增子序列`O(nlog(n))` = `O(n(logn))`

## 代码实现
```python3
import functools
class Solution:
    
    def bestSeqAtIndex(self, height: List[int], weight: List[int]) -> int:
        # 将所有元素按照height从小到大，weight从大到小排序
        def tcmp(a, b):
            if a[0] < b[0] or (a[0] == b[0] and a[1] > b[1]): return -1
            else: return 1
        sortedHw = sorted(zip(height, weight), key = functools.cmp_to_key(tcmp))
        # 在排好序的数组中，求weight严格单调递增的最长子序列的长度
        w = [hw[1] for hw in sortedHw]
        return self.lengthOfLIS(w)

    # 求一个数组的最长严格单增子序列的长度
    def lengthOfLIS(self, nums: List[int]):

        if len(nums) == 0: return 0
        dp, maxlen = [0, nums[0]], 1
        for i in range(1, len(nums)):
            if nums[i] > dp[maxlen]:
                dp.append(nums[i])
                maxlen += 1
            else:
                l, h = 1, maxlen
                while l < h:
                    m = (l + h) // 2
                    if dp[m] < nums[i]: l = m+1
                    else: h = m
                dp[l] = nums[i]
        return maxlen
```