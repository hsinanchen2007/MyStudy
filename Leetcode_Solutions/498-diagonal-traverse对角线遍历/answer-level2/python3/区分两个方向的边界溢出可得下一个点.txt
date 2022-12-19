```
class Solution:
    def findDiagonalOrder(self, matrix: List[List[int]]) -> List[int]:
        directions = [[-1,1],[1,-1]]
        m = len(matrix)
        if m==0:
            return []
        if m==1:
            return matrix[0]
        n = len(matrix[0])
        if n==1:
            print('hahaahha')
            result =[]
            for i in range(m):
                result.append(matrix[i][0])
            return result
        cur_axis = (0,0)
        stack = []
        visited = [[False for _ in range(n)] for _ in range(m)]
        result = []
        stack.append((cur_axis))
        
        while stack:
            x,y = stack.pop()
            visited[x][y] = True
            result.append(matrix[x][y])
            
            if x == m-1 and y == n-1:
                a=0
                break
            
            new_x1,new_y1 = (x+1,y-1)            
            new_x2,new_y2 = (x-1,y+1)
            
            
            if 0<=new_x1<m and 0<=new_y1<n and not visited[new_x1][new_y1]:
                stack.append((new_x1,new_y1))
                continue
            if 0<=new_x2<m and 0<=new_y2<n and not visited[new_x2][new_y2]: 
                stack.append((new_x2,new_y2))
                continue
            
            if new_x2 == -1:
                new_x2 = 0
                new_y2 = y+1 
            if new_y2 == n:
                new_x2 = x +1
                new_y2 = n-1  

                
            if not visited[new_x2][new_y2]:
                stack.append((new_x2,new_y2))
                continue
                
            if new_y1 == -1:
                new_x1 = x +1
                new_y1 = 0      
            if new_x1 == m:
                new_x1 = m-1
                new_y1 = y+1
            if not visited[new_x1][new_y1]:
                stack.append((new_x1,new_y1))
                continue                    
        return result
            
```
