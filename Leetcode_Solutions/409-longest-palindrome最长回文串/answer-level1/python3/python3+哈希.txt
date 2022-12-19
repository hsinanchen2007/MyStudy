### 解题思路
直接看代码，很容易理解

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        cnt = collections.Counter(s)
        ans = 0
        is_add = False
        for value in cnt.values():
            tmp = value % 2
            if tmp == 0:
                ans += value
            else:
                ans += (value - tmp)
                is_add = True
        return ans+1 if is_add else ans
```