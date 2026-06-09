### 解题思路
如题目采用类似字典的方法，用enumerate遍历每一个列表中的元素做成一个索引，即nums = [(0,2),(1,7),(3,11),(4,15)] ，计算目标值和数组中的差值，例如9-2 = 7 则7在哈希表中，即直接返回2和7的索引

### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}
        for idx, num in enumerate(nums):
            if target - num in hashmap:
                return [hashmap[target - num],idx]
            else:
                hashmap[num] = idx
            

```