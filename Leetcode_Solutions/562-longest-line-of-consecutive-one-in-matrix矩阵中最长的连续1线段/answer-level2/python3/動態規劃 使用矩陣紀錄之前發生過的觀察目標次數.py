### 解题思路
動態規劃 使用矩陣紀錄之前發生過的觀察目標次數
有發生就把值+1 一路記下所有位置發生過的次數
最後再找出最大值即可

### 代码

```python3
import numpy as np
class Solution:
    def longestLine(self, M: List[List[int]]) -> int:
        if not M:
            return 0

        V  = np.zeros((len(M)+2, len(M[0])+2))
        H  = np.zeros((len(M)+2, len(M[0])+2))
        D  = np.zeros((len(M)+2, len(M[0])+2))
        ID = np.zeros((len(M)+2, len(M[0])+2))

        for i in range(1, len(V)-1):
            for j in range(1, len(V[0])-1):
                if M[i-1][j-1] == 1:
                   V[i][j] = V[i-1][j] + 1
                   H[i][j] = H[i][j-1] + 1
                   D[i][j] = D[i-1][j-1] + 1
                   ID[i][j] = ID[i-1][j+1] + 1

        res = max(max(max(np.max(V),np.max(H)), np.max(D)), np.max(ID))
        return int(res)
              

```