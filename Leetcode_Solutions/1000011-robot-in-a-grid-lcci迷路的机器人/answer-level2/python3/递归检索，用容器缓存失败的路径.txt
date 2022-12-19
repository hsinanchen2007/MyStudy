### 解题思路
此处撰写解题思路
![13.png](https://pic.leetcode-cn.com/9061cd02a99e91c061d04ae2e787734d11afc9c2dff9ba3c72187d0d16bf20df-13.png)

### 代码

```python3
class Solution:
    def pathWithObstacles(self, obstacleGrid: List[List[int]]) -> List[List[int]]:
        ret = []
        mtx = obstacleGrid
        r = len(mtx)
        if r <= 0:return ret
        c = len(mtx[0])
        if c <= 0:return ret
        self.buff = set()
        return [[0,0]] + ret if self.path(ret,0,0,r,c,mtx) else []

    def path(self,ret:List[List[int]],i:int,j:int,r:int,c:int,mtx:List[List[int]])->bool:
        if (i,j) in self.buff:return False
        if mtx[i][j] != 0:return False
        if i == r-1 and j == c-1:return True
        tmp = [[1,0],[0,1]]
        for tp in tmp:
            nxi = i+tp[0]
            nxj = j+tp[1]
            if 0 <= nxi < r and 0 <= nxj < c and mtx[nxi][nxj] == 0:
                ret.append([nxi,nxj])
                if self.path(ret,nxi,nxj,r,c,mtx):return True
                ret.pop()
        self.buff.add((i,j))
        return False
        
        
        

```