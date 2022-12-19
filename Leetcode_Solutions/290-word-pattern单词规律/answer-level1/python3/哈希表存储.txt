### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def wordPattern(self, pattern: str, str: str) -> bool:
        dic = {}
        s = str.split()
        if len(pattern) != len(s):
            return False
        record = []
        for i in range(len(pattern)):
            if pattern[i] not in dic:
                if s[i] not in record:
                    record.append(s[i])
                    dic[pattern[i]] = s[i]
                else:return False
            elif dic[pattern[i]] != s[i]:
                return False
        return True
```