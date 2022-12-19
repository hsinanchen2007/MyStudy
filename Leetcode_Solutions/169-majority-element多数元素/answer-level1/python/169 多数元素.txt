### 解题思路
通过dict实现。

### 代码

```python
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        setnums = {}
        n = len(nums)
        if n == 1:
            return nums[0]
        elif n == 0:
            return None
        # print n
        for i in range(n):
            if nums[i] not in setnums:
                setnums[nums[i]] = []
            if nums[i] in setnums:
                setnums[nums[i]].append(i)
            
        for i in setnums.keys():
            if len(setnums[i]) > n/2:
                return i
```