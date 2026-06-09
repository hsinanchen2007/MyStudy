### 解题思路
A的ASCII值为65，当n<26时，直接返回其对应的字符串，当n>26时，对其进行取整，继续求其对应的字符串。

### 代码

```python3
class Solution:
    def convertToTitle(self, n: int) -> str:
        s = ''
        while n > 0:
            n -= 1
            s = chr(n%26+65) + s
            n =n//26
        return s
```