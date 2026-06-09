### 解题思路
创建字典 遍历字典

### 代码

```python3
class Solution:
    def firstUniqChar(self, s: str) -> str:
        dic = dict()
        for c in s:
            if c in dic:
                dic[c] += 1
            else:
                dic[c] = 1
        for i in dic:
            if dic[i] == 1:
                return i
        return " "
```