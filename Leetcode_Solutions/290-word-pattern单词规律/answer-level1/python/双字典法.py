### 解题思路
本题采用两个字典，完成pattern<->str的双向映射。然后根据索引下标逐个核对映射关系是否与字典中的相同。如果字典中不存在，就创建新的索引；如果字典中存在，判断是否相等，如果不相等，说明没有规律，返回False。

### 代码

```python3
class Solution:
    def wordPattern(self, pattern: str, str: str) -> bool:
        d = {}
        s = {}
        l_str = str.split(' ')
        if len(pattern)!=len(l_str):
            return False
        for i in range(len(pattern)):
            if pattern[i] not in d.keys():
                d[pattern[i]]=l_str[i]
            elif d[pattern[i]]!=l_str[i]:
                return False
            if l_str[i] not in s.keys():
                s[l_str[i]]=pattern[i]
            elif s[l_str[i]]!=pattern[i]:
                return False
        return True
```