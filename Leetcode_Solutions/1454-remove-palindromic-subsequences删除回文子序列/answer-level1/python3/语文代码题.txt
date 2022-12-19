### 解题思路
最多删除2次。。。。
### 代码

```python3
class Solution:
    def removePalindromeSub(self, s: str) -> int:
        if s == '':
            return 0
        return 1 if s == s[::-1] else 2
```