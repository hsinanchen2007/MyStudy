### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def titleToNumber(self, s: str) -> int:
        num = 0
        i = len(s) - 1
        for item in s:
            num += (ord(item) - 64) * (26** i) 
            i -= 1
        return num

```