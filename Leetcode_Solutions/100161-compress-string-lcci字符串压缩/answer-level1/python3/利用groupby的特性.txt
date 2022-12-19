### 解题思路
itertools包中的groupby中的分组性质是将连续的相同元素划分为一组，这一性质恰巧可以用在此处
### 代码

```python3
from itertools import groupby
class Solution:
    def compressString(self, S: str) -> str:
            if not S:
                return S
            short_s = "".join(['{}{}'.format(key, len(list(value))) for key, value in groupby(S)])
    
            if len(short_s) >= len(S):
                return S
            else:
                return short_s
```