```
class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        #把需要填的索引号放入一个列表里
        resolving_list=[]
        for i in range(9):
            for j in range(9):
                if board[i][j] =='.':
                    resolving_list.append((i,j))

        #验证数值是否符合要求
        def verifying(x,location):
            #验证行
            for j in range(9):
                if board[location[0]][j]==x and j!=location[1]:
                    return False
            #验证列
            for i in range(9):
                if board[i][location[1]]==x and i!=location[0]:
                    return False
            #验证块
            i_start=location[0]//3*3
            j_start=location[1]//3*3
            for i in range(i_start,i_start+3):
                for j in range(j_start,j_start+3):
                    if board[i][j]==x and i!=location[0] and j!=location[1]:
                        return False
            return True

        #递归填入数字
        def resolving(i):
            if i==len(resolving_list):
                return True
            for x in range(1,10):
                if verifying(str(x),resolving_list[i]):
                    board[resolving_list[i][0]][resolving_list[i][1]]=str(x)
                    if resolving(i+1):
                        return True
                    else:
                        board[resolving_list[i][0]][resolving_list[i][1]] ='.'
            return False

        resolving(0)
```
