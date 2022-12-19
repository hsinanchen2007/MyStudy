![image.png](https://pic.leetcode-cn.com/6b19a6e7a276c141a9edb4fc78d6378bc945e4df12e89a30f8b6033299d12211-image.png)

溢出判断恶心
```
class Solution:
    def divide(self, a: int, b: int) -> int:
        if a==0:return 0
        elif a*b>0:sym=1
        else:sym=-1
        a,b=abs(a),abs(b)
        t=b
        tn=1
        ans=0
        while a>=b:
            if a>=t:
                a-=t
                ans+=tn
                t+=t
                tn+=tn
            else:
                t=b
                tn=1
        ans*=sym
        if ans>2147483647:
            return 2147483647
        return ans
```
