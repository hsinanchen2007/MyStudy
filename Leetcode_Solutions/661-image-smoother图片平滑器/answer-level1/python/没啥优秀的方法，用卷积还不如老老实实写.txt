### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def imageSmoother(self, M):
        """
        :type M: List[List[int]]
        :rtype: List[List[int]]
        """
        r,c=len(M),len(M[0])
        res=[[0]*c for i in range(r)]
        direct=[(x,y) for x in range(-1,2) for y in range(-1,2)]
        for i in range(r):
            for j in range(c):
                tmp=[M[i+x][j+y] for x,y in direct  if 0<=i+x<r and 0<=j+y<c]
                res[i][j]=sum(tmp)/len(tmp)
        return res
```