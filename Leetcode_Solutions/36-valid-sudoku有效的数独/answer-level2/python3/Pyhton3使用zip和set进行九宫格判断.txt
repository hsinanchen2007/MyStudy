MAXROWORCLUMNLEN= 9
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        littleBlockgrid = []
        rowandcolumn = []
        for i in range(MAXROWORCLUMNLEN):
            #遍历每一行列表
            if self.roworcolumnCheck(board[i]) == False:
                return False
            #使用zip打包后遍历每一列
            for i in zip(*board):
                if self.roworcolumnCheck(i) == False:
                    return False
        #小宫格同样使用zip打包后进行判断
        for j in range(0,MAXROWORCLUMNLEN,3):
            for k in range(0,MAXROWORCLUMNLEN,3):
                rowandcolumn = list(zip(board[j], board[j+1], board[j+2]))
                print(rowandcolumn)
                littleBlockgrid = rowandcolumn[k] + rowandcolumn[k+1] + rowandcolumn[k+2]
                print(littleBlockgrid)
                if self.roworcolumnCheck(littleBlockgrid) == False:
                    return False 
        return True
    #每行列以及3X3小宫格作为列表传入判断，可以使用过滤函数或者计数函数统计'.'的数量，使用set过滤掉重复的值，然后判断长度识别是否有数字重复即可
    def roworcolumnCheck(self, list_rc):
        specialnum = list_rc.count('.')
        if len(set(list_rc)) + specialnum -1 == MAXROWORCLUMNLEN:
            return True
        return False