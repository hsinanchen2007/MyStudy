### 解题思路
先切片，再反转，然后合并

### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join([i[::-1] for i in s.split()])
```