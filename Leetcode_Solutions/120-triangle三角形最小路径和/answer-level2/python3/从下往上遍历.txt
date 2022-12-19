### 解题思路
此处撰写解题思路
1. 因为最小的值就是从第一行一直到最后一行的相邻和最小，那么从下往上，如果相邻和越小那么到达最顶层的时候和也是最小。
### 代码

```python3
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        n = len(triangle)
        if n == 1:
            return triangle[0][0]
        for i in range(n-1,0,-1):
            for j in range(len(triangle[i-1])):
                triangle[i-1][j] = min(triangle[i-1][j]+triangle[i][j],triangle[i-1][j]+triangle[i][j+1])
        return triangle[0][0]
```