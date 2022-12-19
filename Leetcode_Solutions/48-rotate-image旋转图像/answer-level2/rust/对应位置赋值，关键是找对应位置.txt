```rust
impl Solution {
    pub fn rotate(matrix: &mut Vec<Vec<i32>>) {
        let m = matrix.len() - 1;
        for r in 0..m/2+1 {
            for i in r..m-r {
                let tmp = matrix[m-i][r];
                matrix[m-i][r] = matrix[m-r][m-i];
                matrix[m-r][m-i] = matrix[i][m-r];
                matrix[i][m-r] = matrix[r][i];
                matrix[r][i] = tmp;
            }
        }
    }
}
```
