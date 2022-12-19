### 解题思路
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:

        动态规划？没感觉出来呀，求解的目标作为优化的目标，子问题是否对父问题有增益效果，选择最大值
        思想是把子数组的和作为整体考虑，如果和大于0，则对于最大结果来说是有增益的，小于0，则没有增益，需要舍弃，
        遍历整个数组，并对和进行判断，并取当前最大的值。直至遍历结束

        初始值：sum  = 0
        子问题：当前数组和是否具有增益效果
        递推：有增益效果则+元素，没有增益效果就舍弃
        最后求解，遍历数组，把子数组的和作为整体考虑，如果和大于0，则对于最大结果来说是有增益的，小于0，则没有增益，需要舍弃，
        遍历整个数组，并对和进行判断，并取当前最大的值。直至遍历结束



### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        import sys
        max_sum = 0
        final_max = -sys.maxsize

        for num in nums:
            if max_sum > 0:
                max_sum += num
            else:
                max_sum = num
            final_max = max(max_sum, final_max)
        return final_max




```