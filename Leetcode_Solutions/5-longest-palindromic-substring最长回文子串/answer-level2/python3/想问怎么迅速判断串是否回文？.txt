### 解题思路
只检查串的逆序是否和顺序==可以吗？

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> str:
        s_len = len(s)
        for try_len in range(s_len, 0, -1):
            for start in range(s_len - try_len + 1):
                pub_str = s[start:start+try_len]
                if pub_str == pub_str[::-1]:
                    return pub_str
        return s
```