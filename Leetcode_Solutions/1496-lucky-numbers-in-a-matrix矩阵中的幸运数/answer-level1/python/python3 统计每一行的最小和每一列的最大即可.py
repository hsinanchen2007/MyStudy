### 解题思路
在遍历过程中把每一行的最小值和每一列的最小者记录下来
时间复杂度O(m*n)

### 代码

```python3
class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        #思路：遍历一遍即可得出结果
        #每一行的最小值和每一列的最大值
        m = len(matrix)
        n = len(matrix[0])
        min_list = [float('inf')] * m
        max_list = [float('-inf')] * n
        for i in range(m):
            for j in range(n):
                if matrix[i][j] < min_list[i]:
                    min_list[i] = matrix[i][j]
                if matrix[i][j] > max_list[j]:
                    max_list[j] = matrix[i][j]
        res_set = set(min_list) & set(max_list)
        res = []
        for num in res_set:
            res.append(num)
        return res

```