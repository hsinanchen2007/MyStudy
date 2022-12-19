### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def dominantIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maxNum = max(nums)
        maxIndex = 0
        for i in range(len(nums)):
            if maxNum != nums[i]:
                if maxNum >= 2 * nums[i]:
                    continue
                else:
                    return -1
            else:
                maxIndex = i
        return maxIndex

```