```rust
impl Solution {
    pub fn has_valid_path(grid: Vec<Vec<i32>>) -> bool {
        if grid.is_empty() { return false; }
        if grid.len() == 1 && grid[0].len() == 1 { return true; }
        let check = |mut at: (usize, usize)| {
            if at.0 >= grid.len() || at.1 >= grid[0].len() { return false; }
            let mut vis = vec![vec![false; grid[0].len()]; grid.len()];
            vis[0][0] = true;
            macro_rules! go {
                (up) => { at.0 >= 1 && !vis[at.0 - 1][at.1] && [2, 3, 4].contains(&grid[at.0 - 1][at.1]) };
                (down) => { at.0 + 1 < grid.len() && !vis[at.0 + 1][at.1] && [2, 5, 6].contains(&grid[at.0 + 1][at.1]) };
                (left) => { at.1 >= 1 && !vis[at.0][at.1 - 1] && [1, 4, 6].contains(&grid[at.0][at.1 - 1]) };
                (right) => { at.1 + 1 < grid[0].len() && !vis[at.0][at.1 + 1] && [1, 3, 5].contains(&grid[at.0][at.1 + 1]) };
            }
            while !vis[at.0][at.1] {
                vis[at.0][at.1] = true;
                at = match grid[at.0][at.1] {
                    1 | 3 | 5 if go!(left) => (at.0, at.1 - 1),
                    1 | 4 | 6 if go!(right) => (at.0, at.1 + 1),
                    2 | 5 | 6 if go!(up) => (at.0 - 1, at.1),
                    2 | 3 | 4 if go!(down) => (at.0 + 1, at.1),
                    _ => at,
                };
                if (grid.len() - 1, grid[0].len() - 1) == at { return true; }
            }
            false
        };
        match grid[0][0] {
            1 | 6 => check((0, 1)),
            2 | 3 => check((1, 0)),
            4 => check((1, 0)) || check((0, 1)),
            _ => false,
        }
    }
}
```
