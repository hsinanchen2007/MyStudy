### 解题思路
用了40ms
### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        def get_col(col):
            res = []
            for t in temp:
                res.append(t[col])
            #
            res.reverse()
            return res

        temp = matrix[:]
        for i in range(0, len(temp)):
            matrix[i] = get_col(i)


```