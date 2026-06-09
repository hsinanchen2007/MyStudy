![2019-07-27_124436.jpg](https://pic.leetcode-cn.com/5254ec0ff6bec6d954e9abea05d92d8cdcd5136662d2695883bf9d167d8658a9-2019-07-27_124436.jpg)

核心思路：当我们遍历每一行、每一列时，都把最后一个元素留着，等到下一步再遍历。这样的话，我们每次把矩阵剥离一圈，都对应 4 个非常规整的循环，边界条件清晰不易出错。

```python
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix: return []
        NROW = len(matrix)
        NCOL = len(matrix[0])
        
        def helper(depth):
            nrow, ncol = NROW - 2 * depth, NCOL - 2 * depth
            if nrow <= 0 or ncol <= 0: return []
            if nrow == 1: return matrix[depth][depth:depth+ncol]
            if ncol == 1: return [matrix[r][depth] for r in range(depth, depth + nrow)]

            res = []
            res += matrix[depth][depth:depth+ncol-1]
            res += [matrix[r][depth+ncol-1] for r in range(depth, depth + nrow - 1)]
            res += reversed(matrix[depth+nrow-1][depth+1:depth+ncol])
            res += [matrix[r][depth] for r in reversed(range(depth +1, depth + nrow))]
            return res + helper(depth + 1)
            
        return helper(0)
```

代码中使用了递归，是为了让整个过程更清晰明了。如果要提升效率，可以改写为迭代方式。