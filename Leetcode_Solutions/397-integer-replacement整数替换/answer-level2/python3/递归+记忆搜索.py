递归方法，不过加了个dic用于存储已经尝试过的数字，实现记忆搜索，相当于给递归剪枝了。
时间直接从400ms跳成68ms

```
class Solution:
    def __init__(self):
        self.dic ={}
    
    def integerReplacement(self, n: int) -> int:
        try:
            return self.dic[n]
        except:
            if n==1:
                self.dic[n] = 0
                return 0
            else:
                if n%2==0:
                    self.dic[n] = 1+self.integerReplacement(n//2)
                    return self.dic[n]
                else:
                    self.dic[n] = 1+min(self.integerReplacement(n+1),self.integerReplacement(n-1))
                    return self.dic[n]
```


