### 解题思路
此题的解法挺巧妙的，除了动态规划，还可以用二分查找（题目提示复杂度O(nlogn))，不过还是看了各种解答才理解了二分查找再该题中的应用。
具体如下：
1. 设置dp数组，用于存储上升子序列。
2. 遍历nums，对于每个num，利用二分查找在dp数组查找第一个大于num的数（记下索引）
3. 若索引大于等于dp数组长度，则将num加到dp数组的最后（即num处于上升子序列中，例如原dp=[4,7],num=8,dp应更新为[4,7,8])
4. 若索引小于dp数组长度，则用num替换dp数组中该索引上的值.（例如原dp=[4,7,8]，num=6，则dp更新为[4,6,8])
注意：dp里存的最终结果不一定是原数组中的上升子序列，但dp的长度是最终要求的最长上升子序列

### 代码

```python
class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) <= 0:
            return 0
        dp = []
        for num in nums:
            left, right = 0, len(dp)
            while left < right:
                mid = left + (right - left) / 2
                if dp[mid] >= num:
                    right = mid
                else:
                    left = mid + 1
            if right >= len(dp):
                dp.append(num)
            else:
                dp[right] = num
        return len(dp)
```