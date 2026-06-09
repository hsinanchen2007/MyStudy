### 解题思路
利用python字典记录，只需要循环一次即可。
首先判断新的一个num是否在字典中,如果在输出字典中相应num的value，如果不在，将此num添加进字典中，key为num, value为num在nums中的顺序。
### 代码

```python
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        hash_map = {}
        for i, num in enumerate(nums):
            if target - num in hash_map:
                return [hash_map[target - num], i]
            else:
                hash_map[num] = i
         
```