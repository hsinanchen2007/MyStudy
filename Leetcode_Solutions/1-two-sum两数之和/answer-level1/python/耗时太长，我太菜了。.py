
### 代码

```python
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i in nums:
            element_1 = target - i
            index_list = [index for (index,value) in enumerate(nums) if value == element_1]
            index_1 = nums.index(i)
            if not index_list:
                continue
            if index_1 in index_list:
                index_1 = index_list.pop()
            else:
                index_2 = index_list[0]
                return [index_1, index_2]
            try:
                index_2 = index_list[0]
            except IndexError:
                continue
            return [index_1, index_2]
```