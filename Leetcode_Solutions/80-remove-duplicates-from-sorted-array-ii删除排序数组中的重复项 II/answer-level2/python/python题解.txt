

### 代码

```python
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return None
        i = 0
        j = 2
        temp = 0
        k = nums[0]

        while i < len(nums):
            if nums[i] == k:
                temp += 1               
                if temp > 2:
                    print(i)
                    nums.pop(i)
                else:
                    i += 1
            else:
                k = nums[i]
                temp = 1
                i += 1

        return i







```