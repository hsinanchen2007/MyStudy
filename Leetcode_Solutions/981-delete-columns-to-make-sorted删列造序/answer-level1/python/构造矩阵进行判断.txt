### 解题思路
这道题主要考察构造矩阵知识

### 代码

```python3
class Solution:
    def minDeletionSize(self, A: List[str]) -> int:
        if len(A) == 0 or len(A[0]) == 0:
            return 0
        count = 0
        temp = [[A[i][j] for i in range(len(A))] for j in range(len(A[0]))]
        for i in temp:
            for j in range(len(i) - 1):
                if i[j] > i[j + 1]:
                    count += 1
                    break
        return count
```