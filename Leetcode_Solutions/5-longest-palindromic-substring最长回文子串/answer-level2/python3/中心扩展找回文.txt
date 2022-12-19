### 解题思路
中心扩展找回文，每个中心有四种扩展方式
比如aaabaaa的中心b有以下扩展方式：
b
ab
ba
aba

当中心的右边一个元素与中心相同时，把这两个元素统一看成中心
比如aaabbaaa，当中心为b时，认为中心为bb,则有以下扩展方式：
bb
abb
bba
abba

然后再把是回文串的再看成中心，循环扩展，直到这个中心找不到扩展的回文串为止

PS：感觉代码还可以优化一些

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> str:
        if s == s[::-1]:
            return s
        res = ""
        for i in range(len(s)-1):
            left = i
            right = i+1
            if s[left] == s[right]:
                right += 1
            while left >= 0 and right <= len(s):
                s1 = s[left:right]
                s2 = s[left:right+1]
                s3 = s[left-1:right+1]
                s4 = s[left-1:right]
                left -= 1
                right += 1
                find = 0
                if s1 == s1[::-1]:
                    find = 1
                    if len(s1) > len(res):
                        res = s1
                if s2 == s2[::-1]:
                    find = 1
                    if len(s2) > len(res):
                        res = s2
                if s3 == s3[::-1]:
                    find = 1
                    if len(s3) > len(res):
                        res = s3
                if s4 == s4[::-1]:
                    find = 1
                    if len(s4) > len(res):
                        res = s4
                if find == 0:
                    break
        return res
```