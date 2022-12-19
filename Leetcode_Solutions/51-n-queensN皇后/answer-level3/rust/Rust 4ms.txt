```Rust
impl Solution {
    pub fn solve_n_queens(n: i32) -> Vec<Vec<String>> {
        fn backtrace(board: &mut Vec<Vec<char>>, ans: &mut Vec<Vec<String>>, current_row: usize) {
            if current_row == board.len() {
                ans.push(board.iter().map(|x| x.iter().collect()).collect());
            }

            for i in 0..board.len() {
                if !is_valid(board, current_row, i) {
                    continue;
                }
                board[current_row][i] = 'Q';
                backtrace(board, ans, current_row + 1);
                board[current_row][i] = '.';
            }
        }

        fn is_valid(board: &Vec<Vec<char>>, row: usize, col: usize) -> bool {
            let n = board.len();
            // 检查上方
            for i in 0..row {
                if board[i][col] == 'Q' {
                    return false;
                }
            }
            // 检查左上方
            let mut x = row;
            let mut y = col;
            while x > 0 && y > 0 {
                if board[x - 1][y - 1] == 'Q' {
                    return false;
                }
                x -= 1;
                y -=1;
            }
            // 检查右上方
            x = row;
            y = col + 1;
            while x > 0 && y < n {
                if board[x - 1][y] == 'Q' {
                    return false;
                }
                x -= 1;
                y += 1;
            }
            true
        }
        let mut board = vec![vec!['.'; n as usize]; n as usize];
        let mut ans = vec![];
        if n <= 0 { return ans; }
        backtrace(&mut board, &mut ans, 0);
        ans
    }
}
```
