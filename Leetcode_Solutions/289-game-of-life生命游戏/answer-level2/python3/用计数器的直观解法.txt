### 解题思路
用一个计数器计数返回状态
### 代码

```python3
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        def counter(model,i,j):
            res = 0
            for x in range(i-1,i+2):
                for y in range(j-1,j+2):
                    if x==i and y== j:
                        continue
                    res += model[x][y]
            if (res<2) or (res>3):
                return 0
            elif model[i][j]==1 and (res==2) or (res==3):
                return 1
            elif model[i][j]==0 and (res==3):
                return 1
            else:
                return 0

        m = len(board)
        n = len(board[0])
        model = [[0 for i in range(n+4)] for j in range(m+4)] 
        #model[2:m+2][2:n+2] = copy.deepcopy(board)
        for i in range(m):
            for j in range(n):
                model[2+i][2+j] = board[i][j]
        #model[2][3] = 1
        #print(model)
        #print(board)


        for i in range(2, m+2):
            for j in range(2, n+2):
                board[i-2][j-2] = counter(model,i,j)












```