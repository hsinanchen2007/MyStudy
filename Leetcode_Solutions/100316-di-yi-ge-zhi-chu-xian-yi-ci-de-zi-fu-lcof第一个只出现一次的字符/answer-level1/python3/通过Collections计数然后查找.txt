### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def firstUniqChar(self, s: str) -> str:
        a = list(s)
        b = collections.Counter(a)
        for i in b:
            if b[i]==1:
                return i
        return " "
```