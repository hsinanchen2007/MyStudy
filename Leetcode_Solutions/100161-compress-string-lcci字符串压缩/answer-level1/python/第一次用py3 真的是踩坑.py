### 解题思路
判断空
计数
判断对比

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        sLen=len(S)
        if(sLen<=0):
            return S
        

        listStr = list(S)
        retStr = ''
        sMark = listStr[0]
        sCount=0

        for i in range(len(listStr)):
            if(sMark == listStr[i]):
                sCount+=1
            else:
                retStr=retStr+str(sMark)+str(sCount)
                sMark=listStr[i]
                sCount=1

        retStr=retStr+str(sMark)+str(sCount)

        if(len(retStr)>=sLen):
            return S

        return retStr





```