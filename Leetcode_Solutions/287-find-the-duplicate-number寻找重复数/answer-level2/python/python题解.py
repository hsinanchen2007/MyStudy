### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        low = 1
        high = n
        while low < high:
            count = 0
            mid = (low + high) // 2
            for i in nums:
                if i <= mid:
                    count += 1
            
            if count > mid:
                high = mid
            else:
                low = mid + 1
        return high


```