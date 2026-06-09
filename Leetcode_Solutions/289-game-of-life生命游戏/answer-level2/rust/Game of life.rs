### Output

![image.png](https://pic.leetcode-cn.com/e66ed4b58cc43a81af51a9505e261cc3c2a126d2fd5e5d92887a519a147418f0-image.png)

### Code

```rust []
impl Solution {
    pub fn game_of_life(board: &mut Vec<Vec<i32>>) {
        if board.is_empty() || board[0].is_empty() {
            return;
        }
        let board_copy = board.clone();
        let move_xy = vec![vec![-1i32, -1], vec![-1, 0], vec![-1, 1], vec![0, -1], vec![0, 1], vec![1, -1], vec![1, 0], vec![1, 1]];
        for i in 0..board_copy.len() {
            for j in 0..board_copy[0].len() {
                /* live cell count */
                let mut live_cell_count = 0i32;
                for k in move_xy.iter() {
                    let ii = i as i32 + k[0];
                    let jj = j as i32 + k[1];
                    if ii >= 0 && jj >= 0 && ii < board_copy.len() as i32 && jj < board_copy[0].len() as i32 {
                        if board_copy[ii as usize][jj as usize] == 1 { // live cell count
                            live_cell_count += 1;
                        }
                    }
                }
                /* check live cell count */
                if board_copy[i][j] == 1 { // live cell
                    if live_cell_count != 2 && live_cell_count != 3 {
                        // servive rule 1/3
                        board[i][j] = 0;
                    }
                } else {                   // dead cell
                    if live_cell_count == 3 { 
                        // servive rule 4
                        board[i][j] = 1;
                    }
                }
            }
        }
    }
}
```
