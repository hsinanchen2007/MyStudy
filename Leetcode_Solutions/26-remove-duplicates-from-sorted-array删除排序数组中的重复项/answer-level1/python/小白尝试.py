### 解题思路
此题要求返回值是新列表的长度，并且要求在原列表中删除，主要解决方案就是列表的切片。
列表中第一个元素是肯定保留的，定义一个变量记录此时指针位置，遍历后面的元素，与当前索引位置上的元素比较
不同则索引加一并修改列表中相应索引位置上的值。（此方法只适用已排好序的列表）

### 代码

```python
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        temp_index = 0
        for n in nums:
            if nums[temp_index] == n:
                continue
            
            temp_index += 1
            nums[temp_index] = n
        
        nums = nums[:temp_index+1]
        return len(nums)
        
```