```
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        for i in range(len(triangle)):
            for j in range(len(triangle[i])):
                if i == 0  and j == 0: continue
                elif j == 0: triangle[i][j] = triangle[i-1][j] + triangle[i][j]
                elif j == len(triangle[i]) - 1 : triangle[i][j] = triangle[i-1][-1] + triangle[i][j]
                else: triangle[i][j] = min (triangle[i-1][j-1]+triangle[i][j],triangle[i-1][j]+triangle[i][j])
        return min(triangle[-1])
```
执行用时 :
72 ms, 在所有 python3 提交中击败了94.26%的用户
内存消耗 :
14.7 MB, 在所有 python3 提交中击败了5.04%的用户

这一题需要注意的是，可以直接对数组进行改变，而不需要再开拓新的空间；另外就是边界条件的选取，要注意每一行的长度是随着i的变化而变化的~
