### 解题思路
for循环里用常数会稍微提高一点点执行效率

### 代码

```python3
class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        if len(s) <= 1:
            return False
        length, half = len(s), len(s)//2 + 1
        for i in range(1, half):
            if s == s[:i] * (length // i):
                return True 
        return False

```