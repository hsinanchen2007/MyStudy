
```python3
class Solution:
    def longestPalindrome(self, s: str) -> str:
        N = len(s)
        max_len = 0
        res = ''
        for i in range(N):
            left = i
            right = i
            tmp_len = 1
            while left-1 >= 0 and s[i] == s[left-1]:#向左找与s[i]相同的字符
                left -= 1
                tmp_len += 1
            while right+1 <= N - 1 and s[i] == s[right+1]:#向右找与s[i]相同的字符
                right += 1
                tmp_len += 1
            while left-1 >= 0  and right+1 <= N - 1 and s[left-1] == s[right+1]: #左右同时扩散
                tmp_len += 2
                left -= 1; right += 1
            if max_len < tmp_len:
                max_len = tmp_len
                res = s[left:right+1]
        return res

```