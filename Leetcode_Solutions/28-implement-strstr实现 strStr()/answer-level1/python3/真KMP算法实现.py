暴力法就不写了，以下是KMP算法的实现，附上一个细致讲解KMP算法的博客(https://www.cnblogs.com/ZuoAndFutureGirl/p/9028287.html)
```
class Solution:
    def strStr(self, s: str, p: str) -> int:
        if not p:
            return 0
        def get_next(p):
            next=[-1]
            j=0
            k=-1
            while j<=len(p)-1:
                if k==-1 or p[j]==p[k]:
                    k+=1
                    j+=1
                    next.append(k)
                else:
                    k=next[k]
            return next
        next=get_next(p)
        i=0
        j=0
        while j<=len(p)-1 and i<=len(s)-1:
            if s[i]==p[j] or j==-1:
                i+=1
                j+=1
            else:
                j=next[j]
        if j==len(p):
            return i-j
        else:
            return -1
```