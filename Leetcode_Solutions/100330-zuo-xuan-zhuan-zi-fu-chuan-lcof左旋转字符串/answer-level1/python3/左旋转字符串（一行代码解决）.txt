### 解题思路
直接是利用切片，将字符切割为两部分，然后按照要求拼接。

### 代码

```python3
class Solution:
    def reverseLeftWords(self, s: str, n: int) -> str:
        return s[n :]+ s[: n]
```