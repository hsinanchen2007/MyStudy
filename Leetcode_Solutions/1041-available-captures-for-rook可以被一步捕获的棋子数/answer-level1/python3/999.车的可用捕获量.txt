### 解题思路
- 方法一：定位车，然后向四个方向探索（遇到空继续前进，否则遇到'p'（计数加一），或碰壁，或遇'B'都是换向）
- 方法二：定位车，拿出所在行，所在列，构成两个字符串，去除空格，检查'Rp','pR'的组合总数。
### 代码

```python3
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        for row in board:
            if 'R' in row:
                index = row.index('R')
                x = row
                break
        res = 0
        y = [row[index] for row in board]
        y_string = ''.join(y).replace(".",'')
        x_string = ''.join(x).replace('.','')
        if 'Rp' in x_string:
            res = res + 1
        if 'pR' in x_string:
            res = res + 1
        if 'Rp' in y_string:
            res = res + 1
        if 'pR' in y_string:
            res = res + 1
        return res
        # directions = [(0,1),(0,-1),(-1,0),(1,0)]
        # res = 0
        # for i in range(8):
        #     for j in range(8):
        #         if board[i][j]=='R':
        #             R_i,R_j = i,j
        #             break         

        # for direction in directions:
        #     cur_i,cur_j = R_i+direction[0], R_j+direction[1]
        #     while cur_i<8 and cur_j<8 and cur_i>=0 and cur_j>=0:
        #         if board[cur_i][cur_j]=='p':
        #             res = res + 1
        #             break
        #         if board[cur_i][cur_j]=='B':
        #             break 
        #         cur_i,cur_j = cur_i+direction[0], cur_j+direction[1]
        # return res



        
```