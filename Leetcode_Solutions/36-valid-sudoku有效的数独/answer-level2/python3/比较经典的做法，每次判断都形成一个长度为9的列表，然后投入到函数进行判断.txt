### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isValidRow(self,ls):
        for index in range(1,len(ls)+1):
            if str(index) in ls and ls.count(str(index))!=1:
                return False
        return True
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        #验证每一行是否有效
        for i in range(9):
            m=self.isValidRow(board[i])
            if m==False:
                return m
        #验证每一列是否有效
        temp=[]
        for j in range(9):
            for k in range(9):
                temp.append(board[k][j])
            m = self.isValidRow(temp)
            if m == False:
                return m
            temp = []
        #验证3*3矩阵块中是否有效
        t=0
        for r in range(9):
            for s in range(3*t,3*t+3):
                for w in range(3*(r-3*t),3*(r-3*t)+3):
                    temp.append(board[s][w])
            m = self.isValidRow(temp)
            if m == False:
                return m
            temp = []
            if (r+1)%3==0:
                t+=1

        return True


```