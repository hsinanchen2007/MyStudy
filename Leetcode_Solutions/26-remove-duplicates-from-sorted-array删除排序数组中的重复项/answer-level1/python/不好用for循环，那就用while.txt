### 解题思路
小白的笨方法

### 代码

```python
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n=len(nums)-1
        if len(nums)==0:
            return 0
        else:
            while n>0:
                if nums[n]==nums[n-1]:
                    nums.pop(n)
                    n=n-1
                elif nums[n]!=nums[n-1]:
                    n=n-1
        return len(nums)
```