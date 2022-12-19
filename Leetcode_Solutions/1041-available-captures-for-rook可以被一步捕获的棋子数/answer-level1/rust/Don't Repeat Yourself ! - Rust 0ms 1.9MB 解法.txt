这道题并不难，只是需要写一些重复的模板代码。
利用 Rust 的 `Iterator` 抽象，可以避免写重复代码。

> Don't Repeat Yourself!

```Rust
pub fn num_rook_captures(board: Vec<Vec<char>>) -> i32 {
    let (r, c) = find_rook(&board);
    let row = &board[r];
    judge(row[..c].iter().rev()) // left
        + judge(row[c + 1..].iter()) // right
        + judge((0..r).rev().map(|j| &board[j][c])) // up
        + judge((r + 1..8).map(|j| &board[j][c])) // down
}

fn find_rook(board: &Vec<Vec<char>>) -> (usize, usize) {
    for (r, row) in board.iter().enumerate() {
        for (c, ch) in row.iter().enumerate() {
            if *ch == 'R' {
                return (r, c);
            }
        }
    }
    unreachable!()
}

fn judge<'a>(mut itr: impl Iterator<Item = &'a char>) -> i32 {
    while let Some(ch) = itr.next() {
        match *ch {
            'p' => return 1,
            '.' => continue,
            _ => break,
        }
    }
    0
}
```
