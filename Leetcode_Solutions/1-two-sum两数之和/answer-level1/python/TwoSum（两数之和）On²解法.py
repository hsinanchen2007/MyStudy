### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        consume = []
        for i in range(len(nums)):
            if len(consume) == 2:
                return consume
            if (target - nums[i]) in nums:
                for j in range(len(nums)):
                    if nums[j] == (target - nums[i]) and i!= j :
                        consume.append(i)
                        consume.append(j)
                        break
        return consume
```