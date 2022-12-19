## 概述
- 矩形相关的问题，一般一个模式是控制右下角的点，然后通过 `row-l, col`, `row, col-l`, `row-l, col-l` 这三个位置的d[i][j]构造递推；
- 本类似，可以首先构造 `mat_sum`, 其中使得`mat_sum[i][j]`为前`i`行，前`j`列的sum；之后通过`cur_sum = mat_sum[indr][indc] - col_sum - row_sum + corner_sum` 来计算一个局部的方块的sum；
- 由于只需要输出最大方块的边长，那么一个只要又一个方块满足即可，如果边长`l`的方块都不能小于threshold, 那么`l+m`都不可能构成解；

### Solutions
```python
class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        nrow, ncol = len(mat), len(mat[0])
        mat_sum = [[0] * ncol for ind in range(nrow)]
        for indr, irow in enumerate(mat):
            for indc, icol in enumerate(irow):
                mat_sum[indr][indc] += mat[indr][indc]
                if indr>0 and indc>0:
                    mat_sum[indr][indc] += (mat_sum[indr-1][indc] + mat_sum[indr][indc-1] - mat_sum[indr-1][indc-1])
                elif indc == 0:
                    mat_sum[indr][indc] += mat_sum[indr-1][indc]
                elif indr == 0:
                    mat_sum[indr][indc] += mat_sum[indr][indc-1]
        
        res = 0

        for ilen in range(1, min(nrow, ncol)+1):
            cur_found = False
            for indr, irow in enumerate(mat):
                for indc, icol in enumerate(irow):
                    topleft_row = indr - ilen + 1
                    topleft_col = indc - ilen + 1
                    if topleft_col >= 0 and topleft_col < ncol and topleft_row >= 0 and topleft_row < nrow:
                        if not topleft_col:
                            col_sum = 0
                        else:
                            col_sum = mat_sum[indr][topleft_col-1]
                        if not topleft_row:
                            row_sum = 0
                        else:
                            row_sum = mat_sum[topleft_row-1][indc]
                        if not topleft_col or not topleft_row:
                            corner_sum = 0
                        else:
                            corner_sum = mat_sum[topleft_row-1][topleft_col-1]
                        cur_sum = mat_sum[indr][indc] - col_sum - row_sum + corner_sum
                        if cur_sum <= threshold:
                            res = max(res, ilen)
                            # print(cur_sum)
                            cur_found = True
                            break
                if cur_found:
                    break
            if not cur_found:
                break

        return res
```