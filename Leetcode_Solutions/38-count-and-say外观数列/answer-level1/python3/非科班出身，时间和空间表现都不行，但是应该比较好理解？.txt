```
class Solution:
    def countAndSay(self, n: int) -> str:
        a = '1'
        if n==1:
            return a
        for i in range(n-1):
            b = ''
            i = 0 
            count = 1
            while i<len(a):
                if i == len(a)-1 or a[i]!=a[i+1]:
                    b+=str(count)+a[i]
                    i+=1
                    count = 1
                else:
                    while i<len(a)-1 and a[i]==a[i+1]:
                        count+=1
                        i+=1
            a = b
        return a
```
