### 解题思路
如题

### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        # 列表反转
        #listX = list(str(x))
        #listY = listX[::-1]
        #if listX[0] == '-':
        #    listY = listX[:0:-1]
        #    listY = ['-'] + listY
        #sumInt = ''
        #for i,value in enumerate(listY):
        #    sumInt += value
        #out = int(sumInt)
        strA = str(x)
        if strA[0] == '-':
            out = int('-'+strA[:0:-1])
        else:
            out = int(strA[::-1])
        if out < -2**31 or out > 2**31-1:
            return 0
        return out
        
        
```