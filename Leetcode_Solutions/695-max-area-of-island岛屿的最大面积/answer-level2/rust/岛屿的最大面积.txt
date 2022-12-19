### 解题思路
不会优化
### 代码

```rust
impl Solution {
    pub fn max_area_of_island(grid: Vec<Vec<i32>>) -> i32 {
        let mut grid = grid;
        let (a, b) = (grid.len(), grid[0].len());
        let mut max = 0;
        for i in 0..a {
            for j in 0..b {
                if grid[i][j] == 1 {
                    let temp = Solution::get_area(&mut grid, i, j);
                    if temp > max {
                        max = temp;
                    }
                }
            }
        }
        max
    }
    fn get_area(grid: &mut Vec<Vec<i32>>, i: usize, j: usize) -> i32 {
        let mut area = 0;
        area += 1;
        grid[i][j] = 0;
        if j > 0 && grid[i][j - 1] == 1 {
            area += Solution::get_area(grid, i, j - 1);
        }
        if i < (grid.len() - 1) && grid[i + 1][j] == 1 {
            area += Solution::get_area(grid, i + 1, j);
        }
        if j < (grid[0].len() - 1) && grid[i][j + 1] == 1 {
            area += Solution::get_area(grid, i, j + 1);
        }
        if i > 0 && grid[i - 1][j] == 1 {
            area += Solution::get_area(grid, i - 1, j);
        }
        area
    }
}
```