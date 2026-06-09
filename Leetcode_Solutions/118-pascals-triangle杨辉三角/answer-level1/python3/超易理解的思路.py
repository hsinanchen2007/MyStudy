```
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        List=[[0 for _ in range(numRows)]for _ in range(numRows)]
        for k in range(numRows):
            List[k][0]=1
        for i in range(1,numRows):
            for j in range(1,i+1):
                List[i][j]=List[i-1][j-1]+List[i-1][j]
        for s in range(numRows):
            List[s]=List[s][0:s+1]
        return List
```
