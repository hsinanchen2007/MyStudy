### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        m = len(board)
        n = len(board[0])
        # wdil:-1 wdid:0 wlil:1 wlid:2
        for i in range(m):
            for j in range(n):
                # 确定边界
                l = i-1 if i>0 else 0
                r = i+1 if i<m-1 else m-1
                t = j-1 if j>0 else 0
                b = j+1 if j<n-1 else n-1
                # 求相邻细胞和
                sum_ = 0
                for x in range(l,r+1):
                    for y in range(t,b+1):
                        sum_ = sum_+1 if board[x][y]>=1 else sum_
                sum_ -= board[i][j]
                # 判断状态改变的情况
                if sum_==3 and board[i][j]==0:
                    board[i][j] = -1
                elif (sum_<2 or sum_>3) and board[i][j]==1:
                    board[i][j] = 2
        # 更新
        for i in range(m):
            for j in range(n):
                if board[i][j] in [0,2]:
                    board[i][j] = 0
                else:
                    board[i][j] = 1
```