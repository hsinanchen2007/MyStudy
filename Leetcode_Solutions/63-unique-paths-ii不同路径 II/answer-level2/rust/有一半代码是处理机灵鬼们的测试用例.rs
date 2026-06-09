题目要求总最左上走到最右下， 测试案例里grid[0][0]是1， grid[last_row][last_col]是1的。
```
impl Solution {
     pub fn unique_paths_with_obstacles(obstacle_grid: Vec<Vec<i32>>) -> i32 {
        let mut grid = obstacle_grid;
        let row_len = grid.len();
        let col_len = grid[0].len();
        if row_len == 1 {
            if grid[0].contains(&1) {
                return 0;
            } else {
                return 1;
            }
        }
        if col_len == 1 {
            for i in 0..row_len {
                if grid[i][0] == 1 {
                    return 0;
                }
            }
            return 1;
        }
        if grid[row_len - 1][col_len - 1] == 1 || grid[0][0] == 1{
            return 0;
        }
        for i in 0..row_len {
            for j in 0..col_len {
                if grid[i][j] == 1 {
                    grid[i][j] = -1;
                } 
            }
        }
        for i in 1..col_len {
            if grid[0][i] == -1 {
                continue;
            }
            if grid[0][i - 1] == -1 {
                grid[0][i] = -1;
            } else {
                grid[0][i] = 1;
            }
        }
        for i in 1..row_len {
            if grid[i][0] == -1 {
                continue;
            }
            if grid[i - 1][0] == -1 {
                grid[i][0] = -1;
            } else {
                grid[i][0] = 1;
            }
        }

        for i in 1..row_len {
            for j in 1..col_len {
                if grid[i][j] == -1 {
                     
                } else {
                    let mut top = 0;
                    let mut left = 0;
                    if grid[i][j - 1] != -1 {
                        top = grid[i][j - 1];
                    }
                    if grid[i - 1][j] != -1 {
                        left = grid[i - 1][j];
                    }
                    grid[i][j] = top + left;
                }

            }
        }
        grid[row_len - 1][col_len - 1]
    }
}
```
