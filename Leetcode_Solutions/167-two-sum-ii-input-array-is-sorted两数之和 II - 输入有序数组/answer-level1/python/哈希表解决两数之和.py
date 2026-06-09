### 解题思路
刚开始用另一种遍历方法，一直超出范围，后来还是选择哈希表

### 代码

```python
class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        hashmap = {}
        for idx, num in enumerate(numbers):
            if target - num in hashmap:
                print(hashmap)
                return [hashmap[target - num]+1,idx+1]
            else:
                hashmap[num] = idx
```