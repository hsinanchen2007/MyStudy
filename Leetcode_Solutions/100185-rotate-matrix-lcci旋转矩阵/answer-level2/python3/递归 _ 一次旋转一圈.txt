### 解题思路
一个思路，可以改成循环

### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """

        def rotate_rim(start, end):
            if start >= end:
                return
            for i in range(0, end - start):
                switch_chain = [[start, start+i], [start+i, end], [end, end-i], [end-i, start]]
                tmp = matrix[switch_chain[-1][0]][switch_chain[-1][1]]
                for k in range(2, -1, -1):
                    matrix[switch_chain[k+1][0]][switch_chain[k+1][1]] = matrix[switch_chain[k][0]][switch_chain[k][1]]
                matrix[switch_chain[0][0]][switch_chain[0][1]] = tmp
            rotate_rim(start+1, end-1)
        rotate_rim(0, len(matrix)-1)
                




```