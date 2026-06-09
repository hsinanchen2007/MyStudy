### 解题思路
此处撰写解题思路
对于dic.get(c,0)函数，当字典dic如果存在c的键时，直接返回当前键值。否则返回0。
最后对s进行循环找第一个为1的键
### 代码

```python3
class Solution:
    def firstUniqChar(self, s: str) -> str:
        dic = {}
        for c in s:
            dic[c] = dic.get(c, 0) + 1
        for c in s:
            if dic[c] == 1: return c
        return ' '


        
```