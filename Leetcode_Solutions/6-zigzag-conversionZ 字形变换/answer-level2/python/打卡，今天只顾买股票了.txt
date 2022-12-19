
### 代码

```python3
class Solution:
    def convert(self, s: str, numRows: int) -> str:

        if numRows == 1:
            return(s)
        c1 = len(s)//(numRows*2 - 2)
        c2 = len(s)%(numRows*2 - 2)
        num_col = (numRows-1)*c1 + int(c2 > 0) + int(c2>numRows)*(c2-numRows)
        result = [['' for i in range(num_col)] for k in range(numRows)]
        
        for i in range(c1):
            result[0][int(i*(numRows-1))] = s[int(i*(numRows*2 - 2))]
            result[numRows-1][int(i*(numRows-1))] = s[int(i*(numRows*2 - 2)+numRows-1)]
            for row in range(1,numRows-1):
                result[row][int(i*(numRows-1))] = s[int(i*(numRows*2 - 2)+row)]
                result[row][int(i*(numRows-1))+numRows-1-row] = s[int((i+1)*(numRows*2 - 2)-row)]

        for row in range(min(numRows,c2)):
            result[row][int(c1*(numRows-1))] = s[int(c1*(numRows*2 - 2)+row)]

        if c2 > numRows:
            for row in range(c2-numRows):
                result[-2-row][-(c2-numRows)+row] = s[-(c2-numRows)+row]

        # 查看示意图
        # print('\n'.join(['\t'.join(i) for i in result]))
        
        return(''.join([''.join(i) for i in result]))


```