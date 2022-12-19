### 解题思路
操作一个字典，遍历两个字符串字母统计次数，最后看字典值是否为0.

### 代码

```python3
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        di = {}
        for i in s:
            try:
                di[i] += 1
            except:
                di[i] = 1
        for i in t:
            try:
                di[i] -= 1
            except:
                return False
        return(not any(di.values()))
```