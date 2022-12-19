其实就是蛇形填数的变种

```python
class Solution:
    def findDiagonalOrder(self, matrix: List[List[int]]) -> List[int]:
        upRight, downLeft = True, False
        x, y = 0, 0
        ans = []
        if len(matrix) == 0:
            return ans
        m, n = len(matrix), len(matrix[0])
        while x < m and y < n:
            # print(matrix[x][y], upRight, downLeft)
            ans.append(matrix[x][y])
            if upRight:
                x -= 1
                y += 1
            elif downLeft:
                x += 1   
                y -= 1
            # print(x, y)    
            # 触右边界    
            if upRight and y > n - 1:
                x, y, upRight, downLeft = x + 2, y - 1, False, True
            # 触顶    
            elif upRight and x < 0:
                x, upRight, downLeft = x + 1, False, True
            # 触底    
            elif downLeft and x > m - 1:
                x, y, upRight, downLeft = x - 1, y + 2, True, False 
            # 触左边界    
            elif downLeft and y < 0:
                x, y, upRight, downLeft = x, y + 1, True, False    
            #print(x, y)    
        return ans
```