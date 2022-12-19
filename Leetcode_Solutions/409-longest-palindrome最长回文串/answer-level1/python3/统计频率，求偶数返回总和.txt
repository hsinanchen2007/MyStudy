### 解题思路
此处撰写解题思路

### 代码

```python3
from collections import Counter
class Solution:
    def longestPalindrome(self, s: str) -> int:
        sum = 0
        for i in Counter(s).values():
            sum = sum + i if i%2==0 else sum + i-1
        return sum if sum==len(s) else sum + 1
```