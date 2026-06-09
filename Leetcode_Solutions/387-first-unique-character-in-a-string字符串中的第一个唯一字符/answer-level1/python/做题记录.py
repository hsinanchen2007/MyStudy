### 解题思路
字典存储字母出现次数

### 代码

```python3
class Solution:
    def firstUniqChar(self, s: str) -> int:
        dic = {}
        for c in s:
            dic[c] = dic[c]+1 if c in dic else 1
        for i in s:
            if dic[i]==1:
                return list(s).index(i)
        return -1
```