```
class Solution(object):
    def luckyNumbers (self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        row_range = range(1, len(matrix[0]))
        col_range = range(1, len(matrix))
        rev = []
        for row_index, row in enumerate(matrix):
            min_index_in_row = find_min_in_row(row, row_range)
            if row_index == find_max_in_col(matrix, min_index_in_row, col_range):
                rev.append(row[min_index_in_row])
        return rev


def find_min_in_row(row, row_range):
    min_index = 0
    for i in row_range:
        if row[i] < row[min_index]:
            min_index = i
    return min_index


def find_max_in_col(matrix, col_num, col_range):
    max_index = 0
    for c in col_range:
        if matrix[c][col_num] > matrix[max_index][col_num]:
            max_index = c
    return max_index
```
寻找每一行的最小值，判断该值是不是每一列的最大值。时间复杂度O(m*n)。

find_min_in_row(row)这样写更清晰。
```
def find_min_in_row(row):
    min_index = 0
    for i in range(1, len(row)):
        if row[i] < row[min_index]:
            min_index = i
    return min_index
```
但是range(1, len(row))是要O(n)的时间的，所以写成了find_min_in_row(row, row_range)让他快一点




