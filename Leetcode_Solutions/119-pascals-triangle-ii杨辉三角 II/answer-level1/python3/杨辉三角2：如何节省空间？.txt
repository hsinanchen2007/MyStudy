这道题相比较于杨辉三角1，不需要存储全部的行列表，因此，每次只要记录上一行的数据即可。
``` Python
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        lastlist = []
        for i in range(0, rowIndex + 1):
            reslist = [None for _ in range(i + 1)]
            reslist[0], reslist[-1] = 1, 1
            for j in range(1, len(reslist) - 1):
                reslist[j] = lastlist[j-1] + lastlist[j]
            lastlist = reslist
        return reslist
        
```
