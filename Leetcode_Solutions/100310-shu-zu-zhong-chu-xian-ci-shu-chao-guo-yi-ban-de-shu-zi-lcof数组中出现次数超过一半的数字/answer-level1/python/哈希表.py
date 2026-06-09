### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 1:
            return nums[0]
        res_dict = {}
        for n in nums:
            if n in res_dict:
                res_dict[n] += 1
                if res_dict[n] > len(nums)/2:
                    return n
            else:
                res_dict[n] = 1
                
```