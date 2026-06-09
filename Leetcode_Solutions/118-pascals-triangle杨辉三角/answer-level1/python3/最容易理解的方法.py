```
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        # 先生成一个都为1金子塔
        res= []
        for i in range(1, numRows+1):
            res.append([1]*i)
        for r, rows in enumerate(res):
            for c, cols in enumerate(rows):
                if r > c and c != 0:
                    res[r][c] = res[r-1][c-1]+res[r-1][c]
        return res
```