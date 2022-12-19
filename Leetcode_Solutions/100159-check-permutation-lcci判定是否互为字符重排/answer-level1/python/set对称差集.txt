### 解题思路
确定两个集合的对称差集是否为空

### 代码

```python3
class Solution:
    def CheckPermutation(self, s1: str, s2: str) -> bool:
        return not bool(set(s1) ^ set(s2))
```

