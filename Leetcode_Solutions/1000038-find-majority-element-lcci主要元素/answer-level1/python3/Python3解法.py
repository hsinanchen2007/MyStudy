### 解题思路
先数出所有元素个数,然后找出出现次数最多的那个key.

### 代码

```python3
class Solution:
    def majorityElement(self, nums):
        from collections import Counter
        dct = Counter(nums)
        val = max(dct.values())
        if val <= len(nums)//2:
            return -1
        for i in dct:
            if dct[i] == val:
                return i
```