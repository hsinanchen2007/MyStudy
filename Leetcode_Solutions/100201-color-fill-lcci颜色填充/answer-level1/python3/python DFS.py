### 解题思路
参考岛屿数量问题

### 代码

```python3
class Solution:
    direction = [[0,1],[1,0],[0,-1],[-1,0]]  #右->下->左->上
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        m, n = len(image), len(image[0])
        oriColor = image[sr][sc]
        if(oriColor == newColor):  
            return image
        self.dfs(image,sr,sc,newColor,oriColor,m,n)
        return image

    def dfs(self,image,x,y,newColor,oriColor,m,n):
        image[x][y] = newColor
        for i in range(4):
            tx=x + self.direction[i][0]
            ty=y + self.direction[i][1]
            if(0 <= tx < m and 0 <= ty < n and image[tx][ty] == oriColor):
                self.dfs(image,tx,ty,newColor,oriColor,m,n)
        return
        

        
```