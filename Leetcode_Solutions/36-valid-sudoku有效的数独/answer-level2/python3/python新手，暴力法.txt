```
class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        for i in range(0,9):
            dot=board[i].count(".")
            len_i=len(set(board[i]))
            if len_i < 10-dot:
                return False
        #遍历行
        for i in range(0,9):
            temp=[]
            for ii in range(0,9):
                temp.append(board[ii][i])
            dot=temp.count(".")
            len_i=len(set(temp))
            if len_i < 10-dot:
                return False
        #遍历列
        for k in range(1,4):
            for i in range(1,4):
                temp=[]
                for ii in range(3*k-3,3*k):
                    temp+=board[ii][3*i-3:3*i]
                dot=temp.count(".")
                len_i=len(set(temp))
                if len_i < 10-dot:
                    return False
        #遍历区块
        return True
```
看了官方题解并没有太懂，索性就暴力写吧，提交结果还行，超过80%的朋友