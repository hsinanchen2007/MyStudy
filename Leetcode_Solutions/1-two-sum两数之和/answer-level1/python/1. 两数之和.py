### 解题思路
和为定值的两个数, 数组位置固定且无序, 用哈希表最快
测试例中每组输入都有答案, 不用考虑边界条件
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
        for i in range(len(nums)):
            if target-nums[i] in dic:
                return [dic[target-nums[i]], i]
            else:
                dic[nums[i]] = i
```