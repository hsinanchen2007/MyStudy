### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        c2v = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        ans = 0
        last_v = c2v[s[0]]
        for ch in s[1:]:
            cur_v = c2v[ch]
            if last_v < cur_v:
                ans -= last_v
            else:
                ans += last_v
            last_v = cur_v
        return ans + last_v
```