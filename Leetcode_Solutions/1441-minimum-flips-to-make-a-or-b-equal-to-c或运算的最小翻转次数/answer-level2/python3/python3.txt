### 解题思路
麻烦解法
### 代码

```python
class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
#按位排列数组
        la,lb,lc=[],[],[]
        while a:
            la.append(a%2)
            a=int(a/2)
        while b:
            lb.append(b%2)
            b=int(b/2)
        while c:
            lc.append(c%2)
            c=int(c/2)
#补齐0，使长度相同
        mx = max(len(la),len(lb),len(lc))
        if len(la)<mx:
            la+=[0 for _ in range(mx-len(la))]
        if len(lb)<mx:
            lb+=[0 for _ in range(mx-len(lb))]
        if len(lc)<mx:
            lc+=[0 for _ in range(mx-len(lc))]
        res = 0
        for i in range(mx):
            if lc[i]==0:
                res+=int(lb[i]==1)
                res+=int(la[i]==1)
            else:
                if lb[i]|la[i]!=1: #一开始以为 ^ 是或
                    res+=1
        return res
```