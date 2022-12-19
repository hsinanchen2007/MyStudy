### 解题思路
hash表 以空间换时间 没用enumerate()

### 代码

```python
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        dic = {}
        num = len(nums)
        for x in range(0,num):
            if nums[x] in dic:
                return [dic[nums[x]],x]
            else:
                dic[target-nums[x]]=x      
```