**利用list的上一行进行构建！**
如：
第3行[1,2,1]

构建以下两行各元素相加
[1,2,1,0]        
[0,1,2,0]
第4行  
[1,3,3,1] 

```
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        rows = [1]
        while len(rows)-1 < rowIndex:
            rows = list(temp1+temp2 for temp1,temp2 in zip(rows+[0],[0]+rows))
        return rows
```

第一篇题解 (●'◡'●)