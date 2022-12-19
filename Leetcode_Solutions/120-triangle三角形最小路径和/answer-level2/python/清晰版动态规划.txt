因为每次只能向下一个或者右下一格，所以可以转换为dp[i][j]+=min(dp[i+1][j],dp[i+1][j+1])
```python
class Solution:
    def minimumTotal(self, t: List[List[int]]) -> int:
        row=len(t)
        
        for y in range(row-1,-1,-1):
            column=len(t[y])
            for x in range(column):
                a=t[y+1][x] if y+1<row else 0
                b=t[y+1][x+1] if y+1<row else 0 #此处没有判断x<column是因为x是当前行索引，而下一行肯定有x+1
                t[y][x]+=min(a,b)
        print(t)
        return t[0][0]
```
