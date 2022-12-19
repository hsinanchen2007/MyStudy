### 解题思路

Python3 提供的工具太好用啦！groupby 恰好解决了本题。

Python3 不能求迭代器的长度，除非把迭代器变成元组或列表，这才有了 `len(tuple(group))`。

### 代码

```python3
from itertools import groupby
from itertools import chain


class Solution:
    def compressString(self, S: str) -> str:
        return min(S, ''.join(chain(*((key, str(len(tuple(group)))) 
            for key, group in groupby(S)))), key=len)
```