### 解题思路
使用二维数组是第一想法，看到解题里的精选答案，真是佩服。二维数组的解法还是发一下，方法虽然又慢又占空间，也要放出来瞅瞅。

### 代码

```python3

class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows==1:
            return s
        arr = [{
            'eleNum': numRows if x==0 else 1,
            'startIndex': 0 if x==0 else (numRows-1-x)
        } for x in range(numRows-1)]
        rollNum = math.floor(len(s)/(2*numRows-2))
        leftNum = len(s)%(2*numRows-2)
        leftRow = leftNum-numRows+1 if leftNum>numRows else 1
        arrItem = [arr for x in range(rollNum)]
        arrItem.append(arr[0:leftRow])
        arrItem = [x for y in arrItem for x in y]
        arrResult = [[] for x in range(len(arrItem))]
        for index,val in enumerate(arrItem):
            for j in range(val['eleNum']):
                if val['startIndex']==0:
                    if len(s)>0:
                        arrResult[index].append(s[0])
                        s=s[1:]
                    else:
                        arrResult[index].append(None)
                else:
                    arrResult[index]=[s[0] if val['startIndex']==x else None for x in range(numRows)]
                    s=s[1:]
        string = ''
        for i in range(numRows):
            for j in range(len(arrResult)):
                if arrResult[j][i] != None:
                    string += arrResult[j][i]
        return string
```