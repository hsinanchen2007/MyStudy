### 解题思路
先遍历，记录每个字符出现顺序，再查找是否有次数为1的字符。

### 代码

```python3
class Solution:
    def firstUniqChar(self, s: str) -> str:
        dic = {}
        for i in range(len(s)):
            dic[s[i]] = dic.get(s[i],0) + 1
        for i in range(len(s)):
            if dic.get(s[i]) == 1:
                return s[i]
        return ' '
```