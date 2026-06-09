```
class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        res = ''
        for i in range(len(s)//(2*k)+1):
            res+=s[2*i*k:2*i*k+k][::-1]+s[2*i*k+k:2*i*k+k+k]
        return res
```
