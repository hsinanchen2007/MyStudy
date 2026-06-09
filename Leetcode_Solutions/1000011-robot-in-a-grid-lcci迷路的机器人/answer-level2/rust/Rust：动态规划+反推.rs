用一个`dp`数组存储一个数对，记录上和左节点是否有路径通往原点。
最后可用一个循环获取其中一条路径，也可以用循环/递归得到所有的路径。

```rust
impl Solution {
   pub fn path_with_obstacles(obstacle_grid: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        if obstacle_grid[0][0] == 1 {
            return vec![];
        }
        // (left, up)
        let x = obstacle_grid.len();
        let y = obstacle_grid[0].len();
        let mut dp = vec![vec![(false, false); y]; x];
        dp[0][0] = (true, true);

        for i in 0..x {
            for j in 0..y {
                if obstacle_grid[i][j] == 0 {
                    if j > 0 {
                        dp[i][j].0 = dp[i][j - 1].0 || dp[i][j - 1].1;
                    }

                    if i > 0 {
                        dp[i][j].1 = dp[i - 1][j].1 || dp[i - 1][j].0;
                    }
                }
            }
        }

        let mut ans = vec![];
        let mut i = x - 1;
        let mut j = y - 1;

        while i != 0 || j != 0 {
            ans.insert(0, vec![i as i32, j as i32]);
            if dp[i][j].0 {
                j = j - 1;
            } else if dp[i][j].1 {
                i = i - 1;
            } else {
                return vec![];
            }
        }
        ans.insert(0, vec![0, 0]);
        return ans;
    }
}
```
