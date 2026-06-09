### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        rowIndex= rowIndex+1
        result=[]
        for i in range(rowIndex):
            now=[1]*(i+1)
            if i>=2:
                for n in range(1, i):
                    now[n]=pre[n]+pre[n-1]
            result += [now]
            pre=now
        return result[-1]

```