### 解题思路
此处撰写解题思路
枚举列表，通过迭代将列表值与下标存放到哈希表中，同时查找与该元素对应的元素是否已在哈希表中。如果存在，返回答案。
时间复杂度O(N)，空间复杂度O(N)。
### 代码

```python3
class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        hashmap = {}
        for index, num in enumerate(nums):
            another_num = target - num
            if another_num in hashmap:
                return [hashmap[another_num], index]
            hashmap[num] = index
        return None
```