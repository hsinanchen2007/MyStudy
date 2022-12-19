### 解题思路
分割——翻转——拼接，return

### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join(reversed(s.split()))
```