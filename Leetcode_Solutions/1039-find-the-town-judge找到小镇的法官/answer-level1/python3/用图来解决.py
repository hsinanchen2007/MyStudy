### 解题思路
时间复杂度：O（n3）
空间复杂度：O（n2）

### 代码

```python3
class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        if not trust:
            return 1
        arr = [[0 for i in range(N+1)] for j in range(N+1)]
        for l in trust:
            if not isinstance(l, list):
                reuturn -1
            if not len(l) == 2:
                return -1
            arr[l[0]][l[1]] += 1

        for i in range(1,N+1):
            satis = True
            for j in range(1,N+1):
                if i == j:
                    continue
                satis &= arr[j][i] != 0 and all(arr[i][k] == 0 for k in range(N+1))
            if satis:
                return i
        return -1
```