### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        l = s.split()
        return ' '.join(l[::-1])
```