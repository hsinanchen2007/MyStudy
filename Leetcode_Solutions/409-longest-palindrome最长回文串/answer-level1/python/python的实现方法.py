### 解题思路
建一个字典，字母出现次数大于等于2的，取其最大的偶数；偶数和等于字符串长度的则返回字符串，否则返回偶数和+1

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        dct = {}
        ans = 0
        for ch in s:
            if ch not in dct:
                dct[ch] = 1
            else:
                dct[ch] += 1
            if dct[ch]==2:
                dct[ch] = 0
                ans += 2
        return ans if ans==len(s) else ans+1
```