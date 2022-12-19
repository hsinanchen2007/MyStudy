
```
class Solution:###比赛时没有考虑len(path)==3的情况加break导致超时
    def numTeams(self, rating):
        self.res=0
        self.dfs(rating,[])
        return self.res
    
    def dfs(self,rating,path):
        if self.is_valid(path):
            self.res += 1
            return
        for i in range(len(rating)):
            if len(path)<3:
                path.append(rating[i])
                self.dfs(rating[i+1:],path)
                path.pop()
            else:###len(path)==3 那么就可以回到上一层了 而不需要继续遍历 
                break
            
    def is_valid(self,p):
        if len(p)==3:
            return p[0]>p[1]>p[2] or p[0]<p[1]<p[2]

```
