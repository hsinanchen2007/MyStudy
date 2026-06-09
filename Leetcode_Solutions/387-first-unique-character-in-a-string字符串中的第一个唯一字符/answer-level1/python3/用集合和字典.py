### 解题思路
用集合去重，用字典统计每个字符出现的次数，变量字符串返回第一个唯一字符

### 代码

```python3
class Solution:
    def firstUniqChar(self, s: str) -> int:
        _set = (set(s))
        _count = {x: s.count(x) for x in _set}
        for i in range(len(s)):
            if _count[s[i]] == 1:
                return i
        return -1
```