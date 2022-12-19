### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def freqAlphabets(self, s: str) -> str:
        for i in range(10, 27):
            s = s.replace("%d#" % i, chr(i + 97 - 1))

        for i in range(10):
            s = s.replace("%d" % i, chr(i + 97 - 1))
        return s
```