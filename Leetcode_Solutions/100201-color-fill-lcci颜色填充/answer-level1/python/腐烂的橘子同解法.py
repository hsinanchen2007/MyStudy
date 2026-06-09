### 解题思路
和腐烂的橘子同样的解法

### 代码

```python3
class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        row=len(image)
        column=len(image[0])
        oldColor=image[sr][sc]
        image[sr][sc]=newColor# 赋值新的颜色
        
        dire=[[-1,0],[1,0],[0,-1],[0,1]]# [y,x]上下左右
        visit=[[False]*column for i in range(row)]
        visit[sr][sc]=True

        queue=[[sr,sc]]
        while True:
            next_queue=[]
            while queue:
                y,x=queue.pop()
                for d in dire:
                    y_new=y+d[0]
                    x_new=x+d[1]
                    if -1<y_new<row and -1<x_new<column and visit[y_new][x_new]==False and image[y_new][x_new]==oldColor:
                        visit[y_new][x_new]=True
                        image[y_new][x_new]=newColor
                        next_queue.append([y_new,x_new])
            if not next_queue:
                break
            else:
                queue =next_queue
        return image




```