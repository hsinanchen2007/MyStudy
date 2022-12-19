
```python []
class Solution:
    def findroot_withcom(self,par,x):
        r=x
        while par[r]!=r:
            par[r]=par[par[r]] #找的时候顺便压缩
            r=par[r]
        return par,r
    
    def numIslands(self, grid: List[List[str]]) -> int:
        m=len(grid)
        if m<1:
            return 0
        n=len(grid[0])
        if n<1:
            return 0
        par={}
        #(i,j)不在par即grid[i][j]==0

        for i in range(m):
            for j in range(n):
                if int(grid[i][j])>0:
                    #四种情况：
                    #左0上0：par为自己；左1上0：par同左；左0上1：par同上
                    #左1上1：par同左，然后把上面的root的par指向同左
                    if (i-1,j) not in par:
                        if (i,j-1) not in par:
                            par[(i,j)]=(i,j)
                        else:
                            par[(i,j)]=par[(i,j-1)]      
                    else:
                        if (i,j-1) not in par:
                            par[(i,j)]=par[(i-1,j)]
                        else:
                            par[(i,j)]=par[(i-1,j)]
                            par,x=self.findroot_withcom(par,(i,j-1))
                            par[x]=par[(i-1,j)]
        roots=[]
        res=0
        #最后数数一共几个不同的根
        for x in par:
            par,y=self.findroot_withcom(par,x)
            if y not in roots:
                roots.append(y)
                res+=1
        return res
```
