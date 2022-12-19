### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def checkPossibility(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if len(nums) < 3:
            return True
        count = 0
        for i in range(len(nums)-1):
            if nums[i] > nums[i+1]:
                count += 1
                m = i+1
                if count > 1:
                    return False
        if count == 0:
            return True
        if m == 1 or m == len(nums)-1 or nums[m-1] <= nums[m+1] or nums[m-2] <= nums[m]:
            return True
        return False
        
```