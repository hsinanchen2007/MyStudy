执行用时 :44 ms, 在所有 Python3 提交中击败了96.49% 的用户。
基本思路，利用杨辉三角的对称性，每行只需算一半即可。

```
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res = [[1] * i for i in range(1, numRows+1)]
        for i in range(2, numRows):
            for j in range(1, (i+3)//2):
                res[i][j] = res[i][i-j] = res[i-1][j] + res[i-1][j-1]  #res[i][j]与res[i][i-j]相等
        return res
```