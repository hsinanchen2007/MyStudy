### python 二分查找

![image.png](https://pic.leetcode-cn.com/002d3a53716720d2d55275313a40bb0d3258fc3e7059c492f0705d693268b4c5-image.png)

```python []
class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        if matrix and matrix[0]:
            p = len(matrix[0])
            for mat in matrix:
                if mat[-1] < target:
                    continue
                if mat[0] > target:
                    return False
                m = bisect.bisect(mat, target, hi = p)
                if mat[m - 1] == target:
                    return True
                p = m
        return False
```

### rust 蛇皮走位

```rust []
impl Solution {
    pub fn find_number_in2_d_array(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        let (m, n) = (matrix.len(), if matrix.len() > 0 {matrix[0].len()} else {0});
        let mut i: usize = 0;
        let mut j: usize = n - 1;
        while i < m && j >= 0 && j < n {
            if matrix[i][j] < target {
                i += 1;
            } else if matrix[i][j] > target {
                j -= 1;
            } else {
                return true;
            }
        }
        false
    }
}
```