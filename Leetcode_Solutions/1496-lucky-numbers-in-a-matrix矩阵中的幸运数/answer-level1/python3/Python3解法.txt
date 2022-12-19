### 解题思路
行最小  matrix   m*n  每行最小的—— m_min
列最大   matrix_temp  n*m 是matrix转置矩阵  每列最大的—— n_max
先找出每行最小数对应所在的列，从转置矩阵中找出该行（也就是原矩阵的该列）最大数，
因为矩阵元素不重复，所以两者相等则为所求幸运数

### 代码

```python3
class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        matrix_temp =[[j[i] for j in matrix] for i in range(len(matrix[0]))]
        # matrix m*n   m-min
        # matrix_temp n*m  n-max
        rst = []
        for i in matrix:
            m_min = min(i)
            min_index = i.index(m_min)
            n_max = max(matrix_temp[min_index])
            if m_min == n_max:
                rst.append(m_min)
        return rst

```