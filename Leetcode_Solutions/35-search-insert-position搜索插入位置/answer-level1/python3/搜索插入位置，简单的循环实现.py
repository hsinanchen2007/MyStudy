### 解题思路
首先判断数组的长度是否为0，数组的第一个值是否比target大，若满足则返回0，否则进行遍历，在数组中找出target的位置找到就返回i,同时记录下比target小的元素的位置记为m，若没有找到target则返回m+1。

### 代码

```python
class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if len(nums)==0 or target<nums[0]:
            return 0
        elif len(nums)>0:
            for i in range(len(nums)):
                if nums[i]==target:
                    return i
                if nums[i]<target:
                    m=i
            return m+1


        
```