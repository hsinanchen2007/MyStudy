### 解题思路
考虑回文字符串是奇数就可以直接用字符串中某个值作为回文中点
如果回文字符串是偶数就要用字符串中某两个连续的值作为回文中点

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> str:
        res_str = ""
        max_len = 0
        
        for i in range(len(s)):
            temp_str = ""
            temp_len = 0
            temp_f = i
            temp_e = i
            while temp_e < len(s) and temp_f >= 0 and s[temp_f] == s[temp_e]:
                temp_str += s[temp_e]
                temp_len += 1
                temp_e += 1
                temp_f -= 1
            else:
                if temp_len * 2 - 1 > max_len:
                    max_len = temp_len * 2 - 1
                    res_str = temp_str[::-1] + temp_str[1:] 

        
        for i in range(len(s) - 1):
            temp_str = ""
            temp_len = 0
            temp_f = i
            temp_e = i+1
            while temp_e < len(s) and temp_f >= 0 and s[temp_f] == s[temp_e]:
                temp_str += s[temp_e]
                temp_len += 1
                temp_e += 1
                temp_f -= 1
            else:
                if temp_len * 2 > max_len:
                    max_len = temp_len * 2
                    res_str = temp_str[::-1] + temp_str[::]
        return res_str
```