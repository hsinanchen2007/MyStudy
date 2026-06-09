### 解题思路
参考官方题解
题意：找所有海洋中离陆地最近距离的最大值。
思路：多源点BFS，每次一搜索（迭代）都走距离为一，从所有陆地/grid为1的点开始搜索，搜索过的标记为-1，这样始终能够保证被
标记为-1的点就是被距离最近的陆地访问了，每迭代一次就代表距离为1，那么最后迭代的次数就是距离，且这个距离为最远的距离。
最后ans - 1是因为最后那一次是没有没被访问过的，还是加了1.

### 代码

```rust
impl Solution {
    pub fn max_distance(mut grid: Vec<Vec<i32>>) -> i32 {
        let mut queue : Vec<(usize,usize)> = Vec::new();
        let mut ans = -1;
        for i in 0..grid.len() {
            for j in 0..grid[i].len() {
                if grid[i][j] == 1 {
                    queue.push((i, j));
                }
            }
        }
        if queue.len() == grid.len() * grid.len() || grid.len() == 0 {
            return ans;
        }

        while !queue.is_empty() {
            let que_len = queue.len();
            for _ in 0..que_len {
                let (x,y) = queue.remove(0);
                if x > 0 && grid[x-1][y] == 0 {
                    grid[x-1][y] = -1;
                    queue.push((x-1,y));
                }
                if x < grid.len() -1 && grid[x+1][y] == 0 {
                    grid[x+1][y] = -1;
                    queue.push((x+1,y));
                }
                if y > 0 && grid[x][y-1] == 0 {
                    grid[x][y-1] = -1;
                    queue.push((x,y-1));
                }
                if y < grid.len() - 1 && grid[x][y+1] == 0 {
                    grid[x][y+1] = -1;
                    queue.push((x,y+1));
                }
            }
            ans += 1;
        }
        ans
    }
}
```