### 解题思路
此处撰写解题思路

### 代码

```rust
impl Solution {
    pub fn unique_paths_with_obstacles(obstacle_grid: Vec<Vec<i32>>) -> i32 {
        let mut obstacle_grid = obstacle_grid;
        let m = obstacle_grid[0].len();
        let n = obstacle_grid.len();

        //起始就结束
        if obstacle_grid[0][0] == 1 {
            return 0;
        }
        //初始化
        obstacle_grid[0][0] = 1;
        for i in 1..m {
            //第一行如果当前为障碍或者前面有障碍都设置为0
            if obstacle_grid[0][i] == 1 || obstacle_grid[0][i-1] == 0 {
                obstacle_grid[0][i] = 0;
            } else {
                obstacle_grid[0][i] = 1;
            }
        } 
        for i in 1..n {
            //第一列如果当前为障碍或者前面有障碍都设置为0
            if obstacle_grid[i][0] == 1 || obstacle_grid[i-1][0] == 0 {
                obstacle_grid[i][0] = 0;
            } else {
                obstacle_grid[i][0] = 1;
            }
        }
        for i in 1..n {
            for j in 1..m {
                //障碍则为0
                if obstacle_grid[i][j] == 1{
                    obstacle_grid[i][j] = 0;
                } else {
                    //转移方程
                    obstacle_grid[i][j] = obstacle_grid[i-1][j] + obstacle_grid[i][j-1];
                }
            }
        }
        obstacle_grid[n-1][m-1]    
    }
}
```