### 解题思路
先写出来再说，哈哈哈。
还没弄清楚collections模块，Counter()方法。
### 代码

```python3
import collections

class Solution:
    def firstUniqChar(self, s: str) -> int:
        char_number = dict(collections.Counter(s))
        print(char_number)
        if 1 not in char_number.values():
            return -1
        char_1 =[]
        number_1 =[]
        for key, value in char_number.items():
            if value == 1:
                char_1.append(key)
        for _ in char_1:
            number_1.append(s.index(_))
        return min(number_1)

```
