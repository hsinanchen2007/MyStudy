### 解题思路
遍历字符串，若当前字符不在集合内且不在剩下字符串内，返回索引；
否则将字符存入集合。

### 代码

```python3
class Solution:
    def firstUniqChar(self, s: str) -> int:
        
        res = set()
        for k in range(len(s)):
            if s[k] not in res and s[k] not in s[k+1:]:
                return k
            else:                 
                res.add(s[k])
        return -1
```