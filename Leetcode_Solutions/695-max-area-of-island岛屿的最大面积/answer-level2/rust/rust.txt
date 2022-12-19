### 解题思路
此处撰写解题思路

### 代码

```rust
impl Solution {

    pub fn max_area_of_island(grid:Vec<Vec<i32>>) -> i32 {
        let mut grid = grid;
        let mut ans = 0;
        for i in 0..grid.len(){
            for j in 0..grid[0].len(){
                ans = ans.max(Solution::dfs(&mut grid,i as i32,j as i32));
            }
        }
        ans
    }
    fn dfs(grid: &mut Vec<Vec<i32>>, cur_i:i32, cur_j: i32) -> i32 {
        if cur_i<0 || cur_j<0 || cur_i==grid.len() as i32 || cur_j==grid[0].len() as i32 || grid[cur_i as usize][cur_j as usize]!=1 {
            return 0;
        }
        grid[cur_i as usize][cur_j as usize]=0;
        let di:Vec<i32> = vec![0,0,1,-1];
        let dj:Vec<i32> = vec![1,-1,0,0];
        let mut ans = 1;
        for i in 0..4 {
            let ni = cur_i + di[i];
            let nj = cur_j + dj[i];
            ans += Solution::dfs(grid, ni, nj);
        }
        ans
    }
}




```