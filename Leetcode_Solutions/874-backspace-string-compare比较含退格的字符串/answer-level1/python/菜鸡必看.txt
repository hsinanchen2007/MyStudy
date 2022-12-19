### 解题思路
优雅就完事了嗷
### 代码

```python3
class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        a=self.helper(S)
        b=self.helper(T)
        return a==b
    def helper(self,t) :
        res=[]
        for i in range(len(t)) :
            if t[i]!="#" :
                res+=t[i]
            elif len(res)>0:
                res.pop(-1)
        return "".join(res)


```