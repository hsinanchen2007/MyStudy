这个是“岛屿数量”的入门版本吧，只要记住DFS/BFS的写法，很容易完成。
详情看我之前[链接](https://leetcode-cn.com/problems/perfect-squares/solution/python3zui-ji-chu-de-bfstao-lu-dai-ma-gua-he-ru-me/)，已经把该说的都说了。
下面就直接贴代码+注释吧：
```
class Solution:
    
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        
        stack = [(sr,sc)] ## 初始栈
        dirs = [(0,1),(0,-1),(1,0),(-1,0)] ## 四个方向
        visited = [] ## 初始已访问节点，避免重复访问
        oldColor = image[sr][sc]
        image[sr][sc] = newColor
        
        while stack:
            
            i,j = stack.pop(0)
            visited.append([i,j])
            
            for ii, jj in dirs:
                
                if (len(image)>i+ii>=0) and (len(image[0])>j+jj>=0) and \
                   (image[i+ii][j+jj] == oldColor) and ([i+ii,j+jj] not in visited):
                    
                    stack.append((i+ii, j+jj))
                    image[i+ii][j+jj] = newColor
                    
        return image
```

执行用时战胜 91.40 % 的 python3 提交记录。