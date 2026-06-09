### 解题思路
解这个题之前，请先解其[简单版本](https://leetcode-cn.com/problems/unique-paths/) 

用 i 表示行索引，j 表示列索引，简单版本的思路是这样子的：

+ 如果 i == 0 或者 j == 0，则到达方格 [i, j] 的路径一定只有一条
+ 否则，到达方格 [i， j]的路径等于到达其左侧和上侧方格路径之和，即 `P[i][j] = P[i-1][j] + P[i][j-1]`
+ 最终返回 `P[i-1][j-1]`

本题多一个障碍物，有障碍物的地方其路径为 0, 并且，由于机器人只能向右或者向下走，如果在第一行或者第一列中出现了障碍物，那么那一行或者列的后续方格的到达数都会为0。举个行的例子。
```
[0, 0, 1, 0, 0]
[0, 0, 0, 0, 0]
```
其部分路径为
```
[?, ?, 0, 0, 0]
[?, ?, ?, ?, ?]
```

2 x 5 的方格中，[0, 2]为障碍物，会直接导致路径P[0, 2]及其后续的P[0, 3]， P[0, 4]均为0。因此，在对 i == 0 或者 j == 0处理时，要令 `P[0][j] = P[0][j-1]`， `P[i][0] =  P[i-1][0]`

只要考虑了这一点，其他的部分就跟简单版本的解法一样了。

### 代码

```rust
impl Solution {
    pub fn unique_paths_with_obstacles(obstacle_grid: Vec<Vec<i32>>) -> i32 {
        let m = obstacle_grid.len();
        let n = obstacle_grid[0].len();    

        let mut cache = vec![vec![0; n]; m];   // 创建一个 m x n 的路径数矩阵

        for i in 0..m {
            for j in 0..n {
                if obstacle_grid[i][j] == 1 {  // 如果这一点有障碍物，则路径数为0
                    cache[i][j] = 0;
                } else if i == 0 && j == 0 {   // 如果是初始值，则路径数为1
                    cache[i][j] = 1;
                } else if i == 0 {
                    cache[i][j] = cache[i][j-1];  // 见上面的解释
                } else if j == 0 {
                    cache[i][j] = cache[i-1][j];  // 见上面的解释
                } else {
                    cache[i][j] = cache[i-1][j] + cache[i][j-1];
                }
            }
        }
        return cache[m-1][n-1];
    }
}
```