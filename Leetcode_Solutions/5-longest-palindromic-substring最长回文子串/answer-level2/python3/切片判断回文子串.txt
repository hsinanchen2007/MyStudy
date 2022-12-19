### 解题思路
切片操作比较简单，但耗时过长，值不值得使用啊？

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> str:
        st = ''
        k = 0
        for i in range(len(s)):
            for j in range(len(s),k,-1):# 从后往前循环，出现的第一个即以s[i]开头的最长的
                a = s[i:j]
                if a == a[::-1]:
                    break
            k = j
            if len(a)>len(st):
                st = a
        return st

```