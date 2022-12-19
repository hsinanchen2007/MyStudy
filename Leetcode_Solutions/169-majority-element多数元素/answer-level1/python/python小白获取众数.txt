### 解题思路
遍历字典取里面的众数

### 代码

```python
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count_dict = {}
        s_count = len(nums)//2
        for item in nums:
            if item in count_dict:
                count_dict[item] += 1
            else:
                count_dict[item] = 1
        for key,value in count_dict.items():
            if count_dict[key] > s_count:
                return (key)
```