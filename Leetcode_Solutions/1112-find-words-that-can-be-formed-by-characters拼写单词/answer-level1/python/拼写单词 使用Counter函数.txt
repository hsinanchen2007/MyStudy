### 解题思路
words中每一元素与Counter取交集

### 代码

```python
from collections import Counter
class Solution(object):
    def countCharacters(self, words, chars):
        len_w = 0
        for w in words:
            ans = Counter(w)
            if ans == (ans & Counter(chars)):
                len_w += len(w)
        return len_w
```