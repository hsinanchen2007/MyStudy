### 解题思路
题目缺少一种测试用列 导致 我这里用if也能通过，其实应该用while
例如对于[2, 3, 1, 0, 1, 5, 6] ，下面这个代码用if就有问题。


```python
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            # print(nums)
            if(i!=nums[i]): # 这里本应该用while(i!=nums[i])
                if nums[nums[i]]==nums[i]:
                    return nums[i]
                tmp=nums[i]
                nums[i],nums[tmp]=nums[tmp],nums[i]
            

```