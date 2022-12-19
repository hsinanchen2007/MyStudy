![image.png](https://pic.leetcode-cn.com/5c125c8a5c23ef2ea454ac009001a9a2dcbc6055d3fd55cc692de297349c2adf-image.png)

```
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        def search(k):
            if k==1:
                result=''
                for i in range(len(N)):
                    result+=N[i]
                return result
            a=1
            for i in range(1,len(N)):
                a*=i
            index=k//a if k%a!=0 else k//a-1
            perm=N.pop(index)
            return perm+search(k-index*a)
        
        N=[chr(49+i) for i in range(n)]
        return search(k)
```
