```Rust
impl Solution {
    pub fn is_toeplitz_matrix(matrix: Vec<Vec<i32>>) -> bool {
        for i in 1..matrix.len() {
            for j in 1..matrix[0].len() {
                if matrix[i - 1][j - 1] != matrix[i][j] {
                    return false;
                }
            }
        }

        true
    }
}
```
[其他题目的Rust题解](https://github.com/fruit-in/LeetCode/blob/master/README_CN.md)
