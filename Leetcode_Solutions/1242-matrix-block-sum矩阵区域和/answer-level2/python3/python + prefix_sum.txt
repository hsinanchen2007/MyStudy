```python
class Solution:
    def matrixBlockSum(self, mat: List[List[int]], K: int) -> List[List[int]]:
        row, col = len(mat), len(mat[0])
        res = [[0] * col for _ in range(row)]
        sum_arr = [[0] * col for _ in range(row)]
        #   1, 2, 3
        #   4, 5, 6
        #   7, 8, 9
        def get_sum(x, y, k, sum_arr):
            p1 = get_area(x + k, y + k, sum_arr)
            p2 = get_area(x + k, y - k - 1, sum_arr)
            p3 = get_area(x - k - 1, y + k, sum_arr)
            p4 = get_area(x - k - 1, y - k - 1, sum_arr)
            return p1 - p2 - p3 + p4

        def get_area(i, j, sum_arr):
            if i < 0 or j < 0: return 0
            i = min(i, row - 1)
            j = min(j, col - 1)
            return sum_arr[i][j]

        def compute_sum_arr(ori_arr, sum_arr):
            for i in range(row):
                left = 0
                for j in range(col):
                    left += ori_arr[i][j]
                    if i == 0: sum_arr[i][j] += left
                    else: sum_arr[i][j] = left + sum_arr[i - 1][j]
        compute_sum_arr(mat, sum_arr)
        for i in range(len(mat)):
            for j in range(len(mat[0])):
                res[i][j] = get_sum(i, j, K, sum_arr)
        return res
```