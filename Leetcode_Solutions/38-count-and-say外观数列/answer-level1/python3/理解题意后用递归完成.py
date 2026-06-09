```
class Solution:
    def countAndSay(self, n: int) -> str:
        if n==1:
            return '1'
        elif 1<n<=30:
            t=self.countAndSay(n-1)
            res=''
            i=0
            while i<len(t):
                s=t[i]
                c=1
                while i<len(t)-1 and t[i+1]==t[i]:
                    c+=1
                    i+=1
                s=str(c)+s
                res+=s
                i+=1
            return res
```
