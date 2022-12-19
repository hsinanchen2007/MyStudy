```
class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:

        row = len(image)#题目说了图像长宽均不为0，不用判断
        col = len(image[0])

        a = image[sr][sc]
        if a == newColor: #此时不用改，直接返回，如果强行用dfs会陷入无限循环
            return image 

        dire=[[0,1],[0,-1],[1,0],[-1,0]]#四个搜索方向

        def  dfs(r, c):

            if 0<=r<row and 0 <= c < col and image[r][c] == a:
                image[r][c] = newColor
                for i in range(4):#分别向四个方向搜索
                    rr = r + dire[i][0]
                    cc = c + dire[i][1]
                    dfs(rr, cc)
        dfs (sr,sc)
        return image
```
