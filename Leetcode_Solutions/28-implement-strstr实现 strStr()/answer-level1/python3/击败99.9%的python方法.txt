```
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        c=-1
        for i in range(len(haystack)-len(needle)+1):
            if haystack[i:i+len(needle)]==needle:
                c=i
                break
        return c
```
![028.png](https://pic.leetcode-cn.com/6af92feb3feb986d23c44850f657c6dc3e240352ec10a74793063e4b5298588a-028.png)
击败99.9%的python用户，看图
