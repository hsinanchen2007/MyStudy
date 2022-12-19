1、首先，先把其中的一个小岛标记为2，另外一个小岛放入到队列中。
2、使用宽度优先搜索，将队列中的元素弹出，并且判断是否与标记为2的小岛相连，如果不相连，把遍历的地方标记为1，并且压入队列，等待下一次遍历搜索。
3、把宽度优先搜索的层数作为最短的桥。

```
def dfs(A, i, j):
    if i<0 or i>= len(A) or j<0 or j >= len(A[0]) or A[i][j]==2 or A[i][j] == 0:
        return
    A[i][j] = 2
    dfs(A, i-1, j)
    dfs(A, i+1, j)
    dfs(A, i, j-1)
    dfs(A, i, j+1)
    
class Solution:
    def shortestBridge(self, A: List[List[int]]) -> int:
        row = len(A)
        column = len(A[0])
        found = False
        stack = []
        direction = [[-1, 0],[1,0],[0,1], [0, -1]]
        for i in range(row):
            for j in range(column):
                if not found and A[i][j] == 1:
                    dfs(A, i, j)

                    found = True
                if found and A[i][j] == 1:
                    stack.append([i,j])
        # bfs
        count = 0
        while len(stack)>0:
            for i in range(len(stack)):
                [x, y] = stack.pop(0)

                for [dx, dy] in direction:
                    nx = x + dx
                    ny = y + dy
                    if nx<0 or nx>=len(A) or ny < 0 or ny>=len(A[0]):
                        continue
                    elif A[nx][ny] == 2:
                        return count
                    elif A[nx][ny] == 1:
                        continue
                    else:
                        A[nx][ny] = 1
                        stack.append([nx,ny])
            count += 1
        return count             

```
