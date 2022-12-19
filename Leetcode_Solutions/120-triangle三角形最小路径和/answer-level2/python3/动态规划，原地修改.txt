```
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        m= len(triangle)
        
        for i in range(m-2, -1, -1):
            for j in range(len(triangle[i])):
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1])
        
        return triangle[0][0]
```
典型的动态规划例题，逆序求最小和值，利用原数组空间记录，不占用额外数组空间
