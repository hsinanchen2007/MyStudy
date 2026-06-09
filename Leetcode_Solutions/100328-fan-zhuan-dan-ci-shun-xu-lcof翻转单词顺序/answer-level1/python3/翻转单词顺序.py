### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.split()
        return ' '.join(words[::-1])
```