class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        for i in range(len(matrix)):
            for j in matrix[i]:
                if target==j:
                    return True
        return False
直接暴力找
![image.png](https://pic.leetcode-cn.com/b82579cf643cbb26f22c1c0f5ab3678ad7bfc9c6920f1c63fe4bd9ef9585db61-image.png)
