### 解题思路
类似习题 [73. 矩阵置零](https://leetcode-cn.com/problems/set-matrix-zeroes/)


#### 对于使用 list 生成的二维数组，一定要用 deepcopy. 不然会出错。
习题[面试题 08.12. 八皇后](https://leetcode-cn.com/problems/eight-queens-lcci/solution/gelthin-hui-su-fa-jie-ba-huang-hou-deepcopy-nonloc/) 也用了 deepcopy.
不过，deepcopy 是通用的 API, 内部有很多判断。使用 board_copy = [[x for x in y] for y in board] 也可以。
#### 官方题解第二种解法，为了节省copy 数组所需要的空间，通过构造新的状态来保存这个数组先前的状态。
例如 ： 
+ 2 代表之前为0现在为 1
+ -1 代表之前为1现在为0
+ 1 代表之前为1，现在仍然为 1
+ 0 代表之前为0， 现在仍然为0
全部更新完成后，再把 2 和 -1 替换成 1， 0

### 代码

```python3
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        import copy
        board_copy = copy.deepcopy(board)  # 果然这里都需要用 deep copy, 不然会报错。
        
        dx, dy = [0,0,1,-1,-1,-1,1,1], [1,-1,0,0,-1,1,1,-1]

        m = len(board)
        n = len(board[0])
        for i in range(m):
            for j in range(n):
                # count live number
                count = 0
                for k in range(8):
                    nx, ny = i+dx[k], j+ dy[k]
                    if 0<=nx<m and 0<=ny<n and board_copy[nx][ny] == 1:
                        count += 1
                if board[i][j] == 1:
                    if count<2:
                        board[i][j] = 0
                    elif count==2 or count ==3:
                        board[i][j] = 1
                    else:
                        board[i][j] = 0
                else:
                    if count == 3:
                        board[i][j] = 1
        
```