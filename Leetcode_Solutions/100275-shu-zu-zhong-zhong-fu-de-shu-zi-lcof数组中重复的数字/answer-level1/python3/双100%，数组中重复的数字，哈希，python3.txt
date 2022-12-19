### 解题思路
用字典统计数字出现的次数，字典的默认值为0
当出现字典中的值大于1时，返回对应的键

### 代码

```python3
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        res = {}
        for i in nums:
            res.setdefault(i, 0)
            res[i] += 1
            if res[i] > 1:
                return i
        return nums[-1]
        
```