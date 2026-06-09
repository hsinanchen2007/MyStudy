### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        b=[]
        def jiechen(a):
            if a==0:
                return 1
            s=1
            for i in range(1,a+1):
                s=s*i
            return s
        for i in range(1,n+1):
            i=str(i)
            b.append(i)
        x=n-1
        d=''
        while b:
            if x<0:
                x=0
            c=int(k//jiechen(x))
            y=int(k%jiechen(x))
            if y ==0:
                c=c-1
            k=k-c*jiechen(x)
            x-=1
            d+=b[c]
            b.remove(b[c])
        return d
            
```