### 解题思路
#### 方法：非递归广度优先搜索
从像素点(sr,sc)位置开始，对相邻的相同像素开始进行渲染；
#### 算法
1. 先比较newColor与image[sr][sc]是否相同，若相同则无需渲染直接返回，否则进入bfs开始渲染。
2. 利用list结构来模仿队列，将(sr,sc)存入队列pos中，每次将pos[0]的位置pop出，并将该位置的像素渲染为newColor；之后检查pos[0]的上下左右四个方向，若相邻像素相同则将其位置append进pos中；一直循环至pos为空。

### 代码

```python3
class Solution:
    '''
    类似连通图的问题，以（sr,sc）为起始坐标找到连通区域（水平或垂直方向元素相同的区域），再将该区域的元素值替换成新的像
    素值。方法：dfs,bfs；这里采用非递归的bfs。
    '''
    def bfs(self, image, sr, sc, newColor, row, col):
        oldColor = image[sr][sc]
        pos = [[sr,sc]]
        while len(pos) != 0:
            sr,sc = pos.pop(0)
            image[sr][sc] = newColor
            # 上
            if sr-1 >= 0 and image[sr-1][sc] == oldColor:
                pos.append([sr-1, sc])
            # 下
            if sr+1 < row and image[sr+1][sc] == oldColor:
                pos.append([sr+1, sc])
            # 左
            if sc-1 >= 0 and image[sr][sc-1] == oldColor:
                pos.append([sr, sc-1])
            # 右
            if sc+1 < col and image[sr][sc+1] == oldColor:
                pos.append([sr, sc+1])
        return image
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        # 空列表的情况
        row = len(image)
        if row == 0:
            return image
        col = len(image[0])
        if col == 0:
            return image
        # 检查坐标(sr,sc)的有效性
        if sr>=0 and row>sr and sc>=0 and col>sc:
            # 如果newColor与原有像素一样，直接返回；否则利用bfs进行渲染。
            if image[sr][sc] == newColor:
                return image
            else:
                return self.bfs(image, sr, sc, newColor, row, col)
        else:
            return image
    
```