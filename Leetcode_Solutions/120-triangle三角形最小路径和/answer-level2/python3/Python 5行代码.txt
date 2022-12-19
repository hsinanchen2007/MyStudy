# 动态规划
1.原地更新每个路径的最小代价
2.第一行直接跳过
3.每行第一个和最后一个由于特殊性，直接在上一行左右各插入一个inf可解决
```
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        for i in range(1, len(triangle)):
            triangle[i-1] = [float('inf')] + triangle[i-1] + [float('inf')]
            for j in range(len(triangle[i])):
                triangle[i][j] += min(triangle[i-1][j], triangle[i-1][j+1])
        return min(triangle[-1]) if triangle else 0
```


