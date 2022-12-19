### 解题思路
用[::-1]来反转字符串，用split来分割字符串

### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        newstr=''.join([e[::-1]+' ' for e in s.split(' ')])
        return newstr[0:len(newstr)-1]
```