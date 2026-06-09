### 解题思路
此处撰写解题思路

### 代码

```python3
from collections import Counter
class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        odd = 0
        counter = Counter(s)
        for key in counter.keys():
            if counter[key] % 2 == 1:
                odd += 1
            if odd > 1:
                return False
        return True
```