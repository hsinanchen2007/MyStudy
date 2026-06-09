### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        ans = 0
        count = collections.Counter(s)
        for i in count.values():
            ans += (i // 2) * 2
        return ans+1 if ans < len(s) else ans
```