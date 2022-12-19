### 解题思路
纯数学法
拐点：(2n-2)x
得到index对拐点坐标取余
当余数比n-1大时在折线上，小时在竖线上

### 代码

```python3
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows==1:
            return s
        #if numRows==2:
            #return 
        zStr=['']*numRows
        for index,everyChar in enumerate(s):
            i=index%(numRows*2-2)
            if i>numRows-1:
                zStr[numRows*2-2-i]+=everyChar
            else:
                zStr[i]+=everyChar
        return ''.join(zStr)
```