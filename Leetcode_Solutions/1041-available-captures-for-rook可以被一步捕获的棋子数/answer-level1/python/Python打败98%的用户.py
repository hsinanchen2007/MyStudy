![image.png](https://pic.leetcode-cn.com/5d9a96cddd513041e70c88d091a58d8e1a0629403069ab8dde7f557f944b8ac1-image.png)
```
class Solution(object):
    def numRookCaptures(self, board):
        """
        :type board: List[List[str]]
        :rtype: int
        """        
        row,col = self.get_R_pos(board)
        #跟车子不同行和不同列的绝对不会被车子捕获到，所以我们只需要车子所在的行和列就好        
        #找出车子所在的行和列，统计行和列分别能捕获的卒子数
        #列需要手动构造
        col_list = [board[i][col] for i in range(0,8)]
        return self.get_p_count(board[row],col) + self.get_p_count(col_list,row)
        
    #判断某一行的车能捕获几个卒
    def get_p_count(self,l,R_pos):
        count = 0
        #左边是否能捕获卒子
        i = R_pos - 1
        while i >= 0:
            if l[i] == "p":
                count += 1
                break
            elif l[i] == "B":
                break
            i -= 1
        #右边是否能捕获卒子
        i = R_pos + 1
        while i <= 7:
            if l[i] == "p":
                count += 1
                break
            elif l[i] == "B":
                break
            i += 1
        return count

    #遍历棋盘，获得车子坐标
    def get_R_pos(self,board):
        for i in range(0,8):
            for j in range(0,8):
                if board[i][j] == "R":
                    return [i,j]
               
                    
```
