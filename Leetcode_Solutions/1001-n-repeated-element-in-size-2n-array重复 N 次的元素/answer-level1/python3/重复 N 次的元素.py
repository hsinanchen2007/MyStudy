### 解题思路
使用字典,很简陋的实现.

### 代码

```python3
class Solution:
    def repeatedNTimes(self, A: List[int]) -> int:
        dicts = {}
        for x in A:
            if x not in dicts:
                dicts[x] = 1
            else:
                dicts[x] += 1
        half_len = len(A) // 2
        for key in dicts:
            if dicts[key] == half_len:
                return key
```