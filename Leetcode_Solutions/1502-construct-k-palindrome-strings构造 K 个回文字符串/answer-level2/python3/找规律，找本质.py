### 解题思路
主要是找不能配对的字母数量，处理字符串长度即可。

### 代码

```python3
from collections import Counter
class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        c = Counter(s)
        odd = 0
        for key in c:
            odd += c[key] % 2

        return odd <= k and len(s) >= k

```