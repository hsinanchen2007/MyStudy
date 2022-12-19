### 解题思路
思路：直接想到深度优先遍历，保存指定下标的值temp。2.遍历 判断条件 是否已经访问和是否等于第一个指定下标值。

### 代码

```python3
class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        #行
        m=len(image)
        #列
        n=len(image[0])
        visited=[[False]*n for _ in range(m)]
        directions=[[-1,0],[1,0],[0,-1],[0,1]]
        temp=image[sr][sc]
        # 深度遍历
        def DFS(i,j):
            visited[i][j]=True
            image[i][j] = newColor
            for d in directions:
                wi,wj=i+d[0],j+d[1]
                if -1<wi<m and -1<wj<n and not visited[wi][wj] and image[wi][wj]==temp:
                    image[wi][wj]=newColor
                    DFS(wi,wj)
        DFS(sr,sc)
        return image
```