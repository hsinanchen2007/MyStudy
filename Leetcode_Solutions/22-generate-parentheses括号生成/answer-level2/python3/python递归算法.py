递归算法，简单易懂

```
class Solution:
    def generateParenthesis(self, n: int):
        self.ans = []
        self.generate("",n,0)
        return(self.ans)
    def generate(self, s: str, c1: int, c2:int) -> None:
        # c1:左括号可用个数
        # c2:右括号可用个数
        if c1 == 0 and c2 == 0:
            self.ans.append(s)
            # return
        if c1 > 0:
            self.generate(s+'(',c1-1,c2+1)
        if c2 > 0:
            self.generate(s+')',c1,c2-1)
```
