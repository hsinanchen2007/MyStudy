### 解题思路

punch in the card. 
just one line. 

### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join(s.split()[::-1])
```