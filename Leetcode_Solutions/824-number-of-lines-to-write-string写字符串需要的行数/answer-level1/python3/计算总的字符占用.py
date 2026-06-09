```
class Solution:
    def numberOfLines(self, widths: List[int], S: str) -> List[int]:
        ans = 0
        for s in S:
            t=widths[ord(s)-97]
            if (ans+t-1)//100 > ans//100:
                ans = 100*(ans//100+1)+t
            else:
                ans+=t
        return [ans//100+1, ans%100]
```
