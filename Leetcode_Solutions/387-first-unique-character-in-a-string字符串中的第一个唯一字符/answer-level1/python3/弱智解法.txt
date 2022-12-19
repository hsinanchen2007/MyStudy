### 解题思路
遍历Counter生成的字典. 如果值是1(证明只有一个这个字母)就返回对应的key的index. 如果没有,返回-1

### 代码

```python3
from collections import Counter
class Solution:
    def firstUniqChar(self, s: str) -> int:
        s_dic = Counter(s)
        for k, v in s_dic.items():
            if v ==1:
               return s.index(k)
        else:
            return -1
```