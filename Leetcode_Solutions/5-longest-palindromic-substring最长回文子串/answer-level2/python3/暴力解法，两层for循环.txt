### 解题思路
此处撰写解题思路
回文字符串，正反相同，因此判断一个字符串是否正反相同即可，再枚举所有子字符串即可暴力求解o(n^2) 

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> str:

        if s ==s[::-1]:
            return s
        res = s[0]
        for i in range(len(s)-1):
            for j in range(i+1,len(s)):
                if (j-i+1)>len(res) and s[i:j+1]==s[i:j+1][::-1]:
                    res = s[i:j+1]
        return res   




```