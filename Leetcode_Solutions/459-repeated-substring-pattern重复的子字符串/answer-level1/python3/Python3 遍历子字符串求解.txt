### 解题思路
遍历所有子字符串，如果其中任意一个重复后可以得到原字符串，则返回True

### 代码

```python3
class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        for i in range(1, len(s)):
            if s[:i]*(len(s)//i) == s:
                return True
        return False
```