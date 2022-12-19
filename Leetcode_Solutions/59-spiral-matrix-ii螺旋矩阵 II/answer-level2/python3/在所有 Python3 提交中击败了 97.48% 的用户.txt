### 解题思路
一圈一圈的来

### 代码

```python3
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        res = [[0 for x in range(n)] for i in range(n) ]
        start = 0
        i = 1
        bound = 0
        if n%2 == 0:
            bound = n//2 -1
        else:
            bound = n//2
        while start <= bound:
            res, i = self.circle(res, start , i)
            start+=1

        return res

    def circle(self, res, start, i):
        n = len(res)
        row = start
        col = start
        res[row][col] = i
        while row == start and col < n - start -1:
            res[row][col] = i
            i += 1
            col += 1

        while row < n - start -1 and col == n - start -1:
            res[row][col] = i
            i += 1
            row+=1
        
        while row == n - start -1 and col > start:
            res[row][col] = i
            i += 1
            col -= 1

        while  row > start and col == start:
            res[row][col] = i
            i += 1
            row -= 1


        return res, i
        
        



```