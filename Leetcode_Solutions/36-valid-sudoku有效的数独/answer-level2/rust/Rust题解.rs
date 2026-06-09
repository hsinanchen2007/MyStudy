### 代码

```rust
impl Solution {
    pub fn is_valid_sudoku(board: Vec<Vec<char>>) -> bool {
        let mut raw: Vec<Vec<i32>> = vec![vec![0; 9]; 9];
        let mut col: Vec<Vec<i32>> = vec![vec![0; 9]; 9];
        let mut block: Vec<Vec<i32>> = vec![vec![0; 9]; 9];
        let n: usize = 9;
        for i in 0..n {
            for j in 0..n {
                if board[i][j] == '.' { continue; }
                let number: usize = (board[i][j].to_digit(10).unwrap() - 1) as usize;
                let n_block: usize = (i / 3 * 3 + j / 3) as usize;
                raw[i][number] += 1;
                col[j][number] += 1;
                block[n_block][number] += 1;
                if raw[i][number] > 1 ||
                 col[j][number] > 1 || 
                 block[n_block][number] > 1 {
                    return false;
                }
            }
        }

        true

    }
}
```