```
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        n1,n2,n3,n4 = 0,0,0,0
        num1,num2 = 0,0
        str2,str3,str4 = "","",""
        def test_str(strr):
            n1 = strr.count(".")
            n2 = len(set(strr))
            if (9 - n1) != (n2 -1):
                return("false")
            else:
                return("true")
        #检查每一行
        for i in range(9):
            n1 = board[i].count('.')
            n2 = len(set(board[i]))
            if (9 - n1) != (n2 - 1):
                return(False)
        #检查每一列
        for i in range(9):
            str1 = ""
            for j in range(9):
                str1 += board[j][i]
            result = test_str(str1)
            if result == "false":
                return(False)
            else:
                pass
        #检查小正方形
        for i in range(9):
            for j in range(9):
                if j < 3:
                    str2 += board[i][j]
                elif 2 < j < 6:
                    str3 += board[i][j]
                else:
                    str4 += board[i][j]
            if (i+1) % 3 == 0:
                result1 = test_str(str2)
                result2 = test_str(str3)
                result3 = test_str(str4)
                if result1 == "false" or result2 == "false" or result3 == "false":
                    return(False)
                else:
                    str2 = ""
                    str3 = ""
                    str4 = ""
        return(True)
```
