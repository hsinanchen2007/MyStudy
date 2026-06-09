### 解题思路
看着官方题解写了个python版的，实质是这一题官方的解法还是很精妙的。

他的核心思想在于，首先从后往前找，找到一个逆序的，比如1 2 3 4 5，因为5 比 4 大，所以称之为逆序，然后确定这个位置i
继续从后往前找，找到第一个比当前位置i大的数字，位置为j，比如1 2 3 4 5，实质上5是第一个比4大的，然后交换这两个数字，
最后对nums[i+1:]进行reverse即可。

### 代码

```python3
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # 首先从后往前找到第一个逆序的 比如1 2 3 那么第一个逆序的就是2 3 找到这个位置
        i = len(nums) - 2
        while i >= 0 and nums[i + 1] <= nums[i]:
            i -= 1
        if i >= 0:
            # 说明找到了这个位置
            # 然后从后往前找到第一个比这个数大的数的位置，比如1 2 3 实质上 第一个比2大的是3
            j = len(nums) - 1
            while j >= 0 and nums[i] >= nums[j]:
                j -= 1
            nums[i], nums[j] = nums[j], nums[i]
        
        self.reverse(nums, i + 1)




    def reverse(self, nums, start):
        """
        将nums从start开始进行反转
        """
        end = len(nums) - 1
        while start < end:
            nums[start], nums[end] = nums[end], nums[start]
            start += 1
            end -= 1



```