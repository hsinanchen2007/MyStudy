### 解题思路
1.找到坐标变化的规律
2.根据规律实现算法
基本思想：由外到内循环调整位置的变化

### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        if n != 1:
            for i in range(n//2+1):  # 外层循环，行的变化
                for j in range(i, n-1-i):   # 列的变化
                    num = 1
                    ni, nj = i, j
                    start = matrix[i][j]
                    while num <= 4:  # 这也是规律，一个数位置变化到下一位置到最终回到原位置，需要循环四次
                        ci, cj = ni, nj  # 当前i，j位置
                        ni, nj = cj, n-1-ci  # i,j即将变化的位置，这就是规律
                        start, matrix[ni][nj] = matrix[ni][nj], start  # 交换即将变化位置的数与起点数，冥思苦想
                        num += 1
                        
```