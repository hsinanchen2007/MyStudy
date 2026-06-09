### 解题思路
每次遍历之后判断是否在后面的字符中出现，所以切片

### 代码

```python3
class Solution:
    def firstUniqChar(self, s: str) -> int:
        for i in s:
            if i not in s[s.index(i)+1:]:
                return s.index(i)
            elif i in s[s.index(i)+1:]:
                continue
        return -1
```