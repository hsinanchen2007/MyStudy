### 解题思路
找到'R'的位置，提取出R所在行和列非'.'的元素，然后进行遍历，需要额外空间

### 代码

```python
class Solution(object):
    def numRookCaptures(self, board):
        r,c = 0,0
        while r < len(board) and c < len(board[0]):
                if board[r][c] == 'R':
                    break
                else:
                    c += 1
                    if c == len(board[0]):
                        r += 1
                        c = 0
        xlist,ylist = [],[]
        for i in board[r]:
            if i != '.':
                xlist.append(i)
        for i in range(len(board)):
            if board[i][c] != '.':
                ylist.append(board[i][c])
        count = 0
        xlist = ['0'] + xlist + ['0']
        ylist = ['0'] + ylist + ['0']
        for index,val in enumerate(xlist):
            if val == 'R':
                if xlist[index-1] == 'p':
                    count += 1
                if xlist[index+1] == 'p':
                    count += 1
        for index,val in enumerate(ylist):
            if val == 'R':
                if ylist[index-1] == 'p':
                    count += 1
                if ylist[index+1] == 'p':
                    count += 1
        return count

```