分别计算每块土地上的建筑表面积即可.

```rs
impl Solution {
    pub fn surface_area(grid: Vec<Vec<i32>>) -> i32 {
        let mut sum = 0;
        for i in 0..grid.len() {
            for j in 0..grid[0].len() {
                if grid[i][j] > 0 {
                    sum += (4 * grid[i][j] + 2);
                }
                if i > 0 {
                    sum -= grid[i-1][j].min(grid[i][j]);
                }
                if i < grid.len()-1 {
                    sum -= grid[i+1][j].min(grid[i][j]);
                }
                if j > 0 {
                    sum -= grid[i][j-1].min(grid[i][j]);
                }
                if j < grid[0].len()-1 {
                    sum -= grid[i][j+1].min(grid[i][j]);
                }
            }
        }
        sum
    }
}
```