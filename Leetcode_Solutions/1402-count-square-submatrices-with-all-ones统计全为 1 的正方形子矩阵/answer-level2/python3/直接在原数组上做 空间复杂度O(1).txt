这道题其实跟求面积最大的正方形那题一样，把最后的动态矩阵求和就是答案了。
本题可以不用另开辟动态数组，直接在原数组上做就行。

```
class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        res = 0
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == 0:continue //最先检测matrix[i][j]是否为0
                //后面的情况都建立在matrix[i][j]为一的情况下，就可以直接总和加一
                elif i == 0 and j == 0:res += 1
                elif i == 0:res +=1
                elif j == 0:res +=1
                else:
                //动态转移方程 
                    matrix[i][j] = min(matrix[i-1][j-1], matrix[i-1][j], matrix[i][j-1]) + 1
                    res += matrix[i][j]
        return res
```
时间复杂度 O(n^2):两层遍历
空间复杂度 O(1):在原数组上修改
第一次写题解，写的比较粗糙，如果有说错的地方还请赐教。