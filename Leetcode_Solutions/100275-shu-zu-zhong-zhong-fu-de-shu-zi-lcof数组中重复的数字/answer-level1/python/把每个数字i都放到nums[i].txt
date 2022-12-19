### 解题思路
RT

### 代码

```python
class Solution(object):
    def findRepeatNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #看到难度是简单,直接暴力搜索了
        #结果当然是超时,好,这道题果然没让我失望
        """
        for i in nums:
            if nums.count(i)>1:
                return i
        """
        #对于每一个数字,尽可能把它放到坐标i的位置.如果已经在了,则下一个
        for i in range(len(nums)):
            if nums[i]==i:
                continue
            else:
                #把nums[i] 放到 坐标为 nums[i]的位置去
                if nums[nums[i]]==nums[i]:
                    return nums[i]
                else:
                    nums[nums[i]],nums[i]=nums[i],nums[nums[i]]

```