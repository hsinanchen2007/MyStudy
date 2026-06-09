### 解题思路
每个元素遍历一次周围元素的状态，硬编的

### 代码

```python3
class Solution:
    def gameOfLife(self, board) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        import copy
        new_board = copy.deepcopy(board)
        for i in range(len(board)):
            for j in range(len(new_board[0])):
                board[i][j] = self.judge_life(new_board,i,j)
        return None
    def judge_life(self,board,x,y):
        """
        两个不可复活,三个可以复活
        """
        life_range = [2,3]
        relife_range = [3]
        nolife_range = [0,1,4,5,6,7,8]
        judge_num = 0
        for i in range(-1,2):
            for j in range (-1,2):
                if i==0 and j==0:
                    judge_num+=0
                else:
                    try :
                        if x+i == -1 or y+j == -1 :
                            judge_num += 0
                        else:
                            if board[x+i][y+j] == 1:
                                judge_num += 1
                    except:
                        judge_num += 0
        if judge_num in life_range and board[x][y] == 1:
            return 1
        elif judge_num in relife_range and board[x][y] == 0:
            return 1
        elif judge_num in nolife_range:
            return 0
        else:
            return 0
```