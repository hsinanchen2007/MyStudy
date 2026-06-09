### 解题思路
> 出现奇数次的多个字符保留一个奇数，其他按-1后的偶数累加即可; 出现偶数次的字符直接累加

### 代码

```python3
from collections import Counter

class Solution:
    def longestPalindrome(self, s: str) -> int:
        counter = Counter(s)
        has_odd = False
        ans = 0
        for c in counter:
            if counter[c] % 2:
                has_odd = True
                ans += counter[c] - 1
            else:
                ans += counter[c]
        if has_odd:
            ans += 1
        return ans
```
