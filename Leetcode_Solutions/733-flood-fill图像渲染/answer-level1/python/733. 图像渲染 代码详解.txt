### 代码

```python
class Solution(object):
    def floodFill(self, image, sr, sc, newColor):
        #运动方向
        dir = [(0,1),(-1,0),(0,-1),(1,0)]
        #访问记录，未被访问为0，已访问为1
        visit = [[0]*len(image[0]) for _ in range(len(image))]
        #开始渲染吧
        #用于存储渲染坐标点
        stack = [(sr,sc)]
        #标记为已访问
        visit[sr][sc] = 1
        #记录原始颜色
        orig_color = image[sr][sc]
        #渲染
        image[sr][sc] = newColor
        while stack:
            x,y = stack.pop(0)
            #更新坐标
            for d in dir:
                new_x,new_y = x + d[0],y + d[1]
                if 0 <= new_x < len(image) and 0 <= new_y < len(image[0]) and not visit[new_x][new_y] and image[new_x][new_y] == orig_color:
                    visit[new_x][new_y] = 1
                    image[new_x][new_y] = newColor
                    #将刚被渲染的点加入stack,以便做下一轮处理
                    stack.append((new_x,new_y))
        return image

```