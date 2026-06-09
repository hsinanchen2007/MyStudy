

### 代码

```python
class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        nums.append('end')
        i = 0
        while nums[i] != 'end':
            if nums[i] == val:
                nums.pop(i)
                i = 0
            else:
                i += 1
        
        nums.pop(i)
        return len(nums)
             
```