### 解题思路

尺取例题

### 代码

```python []
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ans, l, w = 0, 0, collections.defaultdict(int)
        for r, c in enumerate(s):
            w[c] += 1
            while w[c] > 1:
                w[s[l]] -= 1
                l += 1
            ans = max(ans, r - l + 1)
        return ans
```