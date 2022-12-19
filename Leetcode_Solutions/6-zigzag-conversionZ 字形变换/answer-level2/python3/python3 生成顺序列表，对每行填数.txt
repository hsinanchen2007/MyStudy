
``
```python []
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if s == "" or numRows == 1:
            return s
        T = 2 * numRows - 2 # 周期内的元素
        uping = [i for i in range(numRows)] # 往下数的个数
        downing = [i for i in range(numRows-2,0,-1)] # 往上数的个数
        Row = uping + downing # 一个周期内各个数在第几行
        # 一个周期不满  或多个周期情况下，把每一个数所在行都标注出来
        Row = Row * (len(s)//T) + Row[:(len(s)%T)] # len(Row) == len(s)
        
        res = ["" for i in range(numRows)]
        for j,x in enumerate(Row):                
                res[x]= ''.join([res[x],s[j]])
        return ''.join(res)
```

