
```python []
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        y = self.generate(rowIndex+1)
        return y[rowIndex] #题目有点问题，明明取的第四行，却说得第三行，这里做了修正

    def generate(self,numRows):
        if numRows ==0:
            return []
        if numRows ==1:
            return [[1]]
        elif numRows ==2:
            return [[1],[1,1]]
        else:
            final = [[1],[1,1]]
            for i in range(2,numRows):
                i_row =[]  #初始化第i行
                for k in range(i+1):
                    i_row.append(0) #将第i行初始化为0
    
                i_row[0],i_row[-1]=1,1  #将第i行的第一位和最后一位初始化为1
    
                for j in range(1,i):
                    i_row[j]=final[i-1][j-1]+final[i-1][j] #i_row 完成初始化
                final.append(i_row)                       #将final添加新的行
            return final
```

