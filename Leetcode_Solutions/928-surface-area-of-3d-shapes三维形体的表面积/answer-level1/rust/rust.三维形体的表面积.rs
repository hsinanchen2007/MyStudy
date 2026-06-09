### 解题思路
此处撰写解题思路

### 代码

```rust
impl Solution {
    pub fn surface_area(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let mut area=0;
        for i in 0..n{
            for j in 0..n{
                let level = grid[i][j];
                if level>0{
                    area += level*4 + 2;
                    if(i>0){
                        area -= level.min(grid[i-1][j])*2;
                    }
                    if(j>0){
                        area -= level.min(grid[i][j-1])*2;
                    }
                }
            }
        }
        area
    }
}


```