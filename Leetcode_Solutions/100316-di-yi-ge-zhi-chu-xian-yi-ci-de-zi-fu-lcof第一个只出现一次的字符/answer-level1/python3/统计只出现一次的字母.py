### 解题思路
此处撰写解题思路
哈希表
dic  = collections.Counter(s)
### 代码

```python3
class Solution:
    def firstUniqChar(self, s: str) -> str:
        dic = collections.Counter(s)
        for i in s:
            if dic[i] == 1:
                return i
        return " "
```