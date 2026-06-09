```rust
impl Solution {
    pub fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
// 用第一次碰到0的行和列作为标记位置，用非0数初始化
// 以后再遇到0，就在标记行和标记列 记上另一个数字
// 最后检查标记行和标记列，如果是初始化数，就什么也不做
// 如果是 标记数，就置对应的列或者行位00
// 最后置标记行和标记列位0
        let m = matrix.len();
        if m == 0{
            return;
        }
        let n = matrix[0].len();
        if n == 0 {
            return;
        }
        let mut first_row = m +1;
        let mut first_col = n+1;
        const MARK:i32 = 2;
        for i in 0..m {
            for j in 0..n {
                if matrix[i][j] == 0{
                    // first time meet zero
                    if first_row > m{
                        // init row and col to 1
                        first_row = i;
                        first_col = j;
                        //println!("{} {}",i,j);
                        for k in 0..m {
                            if matrix[k][first_col] != 0 {
                                matrix[k][first_col] = MARK;
                            }
                        }
                        for k in 0..n {
                            if matrix[first_row][k] != 0 {
                                matrix[first_row][k] = MARK;
                            }
                        }
                    } else {
                        // meet 0 again and again
                        matrix[first_row][j] = MARK + 1;
                        matrix[i][first_col] = MARK + 1;
                    }
                }
            }
        }
        if first_row < m {
            for k in 0..m {
                if matrix[k][first_col] == MARK + 1 &&
                   k != first_row {
                    for p in 0..n {
                        matrix[k][p] = 0;
                    }
                }
                matrix[k][first_col] = 0;
            }
            for k in 0..n {
                if matrix[first_row][k] == MARK + 1 &&
                   k != first_col {
                    for p in 0..m {
                        matrix[p][k] = 0;
                    }
                }
                matrix[first_row][k] = 0;
            }
        }
    }
}
```
