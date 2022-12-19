### 解题思路
之前一直提交出现越界问题，一脸懵逼的解决了。没想到耗时那么高，暴力法确实不行

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> str:
       maxlen = 1
       res = ""
      ## res = s[0]
       if s == s[::-1]:
          return s
       for i in range (len(s) - 1):
          for j in range(i+1, len(s)):
              if j-i+1 > maxlen and  s[i:j+1] == s[i:j+1][::-1]:
                 maxlen = j-i+1
                 res = s[i:j+1]
       
       if res == "":
          res = s[0]
       return res
```