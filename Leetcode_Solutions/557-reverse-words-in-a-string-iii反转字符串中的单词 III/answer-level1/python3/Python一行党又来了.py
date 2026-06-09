### 解题思路
两次翻转

### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(s.split()[::-1])[::-1]
```