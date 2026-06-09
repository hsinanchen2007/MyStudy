这道题和之前的求岛屿个数的题目如出一辙，只要在处理业务代码地方改下就OK。
还是那个链接[python3最基础的BFS套路代码，适合入门新手！](https://leetcode-cn.com/problems/perfect-squares/solution/python3zui-ji-chu-de-bfstao-lu-dai-ma-gua-he-ru-me/),有了这把菜刀，这题就是砧板上的菜，切就完事！

附上代码如下：
```
class Solution:
    
    def updateMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        
        def BFS(matrix, i, j):
            
            stack = [(i,j,0)] ## 节点的定义：横坐标，纵坐标，当前位置距0的初始步数
            dirs = [(0,1),(0,-1),(1,0),(-1,0)]
            visited = []
            
            while stack:
                
                ii,jj,cur_count = stack.pop(0)
                
                for ix, jx in dirs:
                    
                    if (len(matrix)>ii+ix>=0) and (len(matrix[0])>jj+jx>=0) and ((ii+ix,jj+jx) not in visited) and (matrix[ii+ix][jj+jx]==0):
                        
                        cur_count += 1
                        return cur_count
                    
                    elif (len(matrix)>ii+ix>=0) and (len(matrix[0])>jj+jx>=0) and ((ii+ix,jj+jx) not in visited) and (matrix[ii+ix][jj+jx]!=0):
                        
                        stack.append((ii+ix,jj+jx,cur_count+1))
                        visited.append((ii+ix,jj+jx))
                        
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                
                if matrix[i][j]==0:
                    continue
                else:
                    matrix[i][j] = BFS(matrix,i,j)
                    
        return matrix
```
我的提交执行用时已经战胜 77.12 % 的 python3 提交记录。