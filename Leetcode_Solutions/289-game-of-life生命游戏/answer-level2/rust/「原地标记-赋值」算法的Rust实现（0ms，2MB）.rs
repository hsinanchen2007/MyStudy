要点：
1. 使用`i32`类型的最高位作为标记位，标记需要改动的单元格：
```Rust
const MARKED_ZERO: i32 = std::i32::MIN; // 0x8000000
const MARKED_ONE: i32 = std::i32::MIN + 1; // 0x8000001
```
需要注意，`MASKED_ONE`不能直接用`0x8000001`定义，否则会编译出错。

2. 根据题目要求打表，用于标记：
```Rust
const LIVE_TABLE: [[i32; 9]; 2] = [
    [0, 0, 0, MARKED_ZERO, 0, 0, 0, 0, 0],
    [
        MARKED_ONE, MARKED_ONE, 1, 1, MARKED_ONE, MARKED_ONE, MARKED_ONE, MARKED_ONE, MARKED_ONE,
    ],
];
```
完整解法：
```Rust
pub struct Solution;

impl Solution {
    pub fn game_of_life(board: &mut Vec<Vec<i32>>) {
        let rows = board.len();
        let columns = board[0].len();

        for r in 0..rows {
            for c in 0..columns {
                let count = Solution::count(&board, rows, columns, r, c);
                board[r][c] = LIVE_TABLE[board[r][c] as usize][count as usize];
            }
        }

        for r in 0..rows {
            for c in 0..columns {
                board[r][c] = match board[r][c] {
                    MARKED_ONE => 0,
                    MARKED_ZERO => 1,
                    n => n,
                };
            }
        }
    }

    fn count(board: &[Vec<i32>], rows: usize, columns: usize, r: usize, c: usize) -> i32 {
        let left = c.wrapping_sub(1);
        let right = c + 1;
        let up = r.wrapping_sub(1);
        let down = r + 1;

        let cal = |row: usize, column: usize| -> i32 {
            if row < rows && column < columns {
                board[row][column] & 1
            } else {
                0
            }
        };

        cal(up, left)
            + cal(up, c)
            + cal(up, right)
            + cal(r, left)
            + cal(r, right)
            + cal(down, left)
            + cal(down, c)
            + cal(down, right)
    }
}

// 0x8000000
const MARKED_ZERO: i32 = std::i32::MIN;
// 0x8000001
const MARKED_ONE: i32 = std::i32::MIN + 1;

const LIVE_TABLE: [[i32; 9]; 2] = [
    [0, 0, 0, MARKED_ZERO, 0, 0, 0, 0, 0],
    [
        MARKED_ONE, MARKED_ONE, 1, 1, MARKED_ONE, MARKED_ONE, MARKED_ONE, MARKED_ONE, MARKED_ONE,
    ],
];
```