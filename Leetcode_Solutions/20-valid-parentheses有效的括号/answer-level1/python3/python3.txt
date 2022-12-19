字典 + 栈的思想
```
class Solution:
    def isValid(self, s: str) -> bool:
        def str2int(s):
            d={'(':1,'{':10,'[':100,')':2,'}':11,']':101}
            return d[s]
        s=list(map(str2int, s))
        x=[]
        for i in range(0,len(s)): #如果s为空，这里x不会append任何数，仍为[]
            x.append(s[i])  #把s中的每个数都压进栈
            if len(x)>=2:    
                if x[-1]-x[-2]==1: #如果新进栈的数和前面的数是一对，就都删掉
                    x.pop()
                    x.pop()
        return x==[]

```
