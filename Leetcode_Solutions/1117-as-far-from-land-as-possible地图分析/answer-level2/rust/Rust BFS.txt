### 解题思路
BFS
### 代码

```rust
impl Solution {
    pub fn max_distance(grid: Vec<Vec<i32>>) -> i32 {
        let mut grid=grid;
        let n =grid.len() as i32;
        let mut land = Vec::new();
        for r in (0..n){
            for c in (0..n) {
                if grid[r as usize][c as usize] == 1 {
                    land.push((r,c))
                }
            }
        }
        if land.len()==0 as usize || land.len() ==(n*n) as usize{
            return -1
        }

        let directions= vec![(1,0),(-1,0),(0,1),(0,-1)];
        let mut res=-1;

        while !land.is_empty(){
            res+=1;
            let mut temp = Vec::new();
            for (r,c) in land{
                for (x,y) in &directions{
                    let (nx,ny) = (r+x,c+y);
                    if -1<nx && nx<n &&-1<ny && ny<n && grid[nx as usize][ny as usize]==0 {
                        grid[nx as usize][ny as usize]=-1;
                        temp.push((nx,ny));
                    } 
                }
            }
            land=temp;
        }
        res
    }
}
```