![image.png](https://pic.leetcode-cn.com/c1b9f68f47f1225e273d4955f3658dfa684fd004cbba2501beedd66427be1ea7-image.png)


### 暴力深搜

```python []
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not len(grid) or not len(grid[0]):
            return 0
        m, n = len(grid), len(grid[0])
        f = lambda i, j: not (grid[i].__setitem__(j, None),
            j + 1 < n and grid[i][j + 1] == '1' and f(i, j + 1),
            j > 0 and grid[i][j - 1] == '1' and f(i, j - 1),
            i + 1 < m and grid[i + 1][j] == '1' and f(i + 1, j),
            i > 0 and grid[i - 1][j] == '1' and f(i - 1, j))
        return sum(grid[i][j] == '1' and not f(i, j) for i, j in itertools.product(range(m), range(n)))
```

### 把换行去掉

```python []
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not (m := len(grid)) or not (n := len(grid[0])):
            return 0
        f = lambda i, j: grid[i].__setitem__(j, None) or j + 1 < n and grid[i][j + 1] == '1' and f(i, j + 1) or j > 0 and grid[i][j - 1] == '1' and f(i, j - 1) or i + 1 < m and grid[i + 1][j] == '1' and f(i + 1, j) or i > 0 and grid[i - 1][j] == '1' and f(i - 1, j)
        return sum(grid[i][j] == '1' and not f(i, j) for i in range(m) for j in range(n))
```
```python []
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not (m := len(grid)) or not (n := len(grid[0])):
            return 0
        f = lambda i, j: grid[i][j] == '1' and (grid[i].__setitem__(j, None) or j + 1 < n and f(i, j + 1) or j > 0 and f(i, j - 1) or i + 1 < m and f(i + 1, j) or i > 0 and f(i - 1, j))
        return sum(grid[i][j] == '1' and not f(i, j) for i in range(m) for j in range(n))
```


### 带哨兵的深搜，用空间来换取判断次数，不过并有真的快起来。。

```python []
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not len(grid) or not len(grid[0]):
            return 0
        m, n = len(grid), len(grid[0])
        for a in grid:
            a.append(None)
        grid.append([None] * n)
        f = lambda i, j: grid[i].__setitem__(j, None) \
            or grid[i][j + 1] == '1' and f(i, j + 1) \
            or grid[i][j - 1] == '1' and f(i, j - 1) \
            or grid[i + 1][j] == '1' and f(i + 1, j) \
            or grid[i - 1][j] == '1' and f(i - 1, j)
        ans = 0
        for i, j in itertools.product(range(m), range(n)):
            if grid[i][j] == '1':
                f(i, j)
                ans += 1
        return ans
```

### rust 解法

![image.png](https://pic.leetcode-cn.com/97bfd03bf958980cd41c3241b290640177b179f7a717c54121f6ac2cc5d0a3e4-image.png)

递归

```rust []
impl Solution {
    pub fn num_islands(mut grid: Vec<Vec<char>>) -> i32 {
        if grid.len() == 0 || grid[0].len() == 0 {
            return 0
        }
        let mut ans = 0;
        for i in 0..grid.len() {
            for j in 0..grid[i].len() {
                if grid[i][j] == '1'{
                    f(i, j, &mut grid);
                    ans += 1;
                }
            }
        }
        ans
    }
}
fn f(i: usize, j: usize, grid: &mut Vec<Vec<char>>) {
    if grid[i][j] == '1'{
        grid[i][j] = '0';
        if j + 1 < grid[0].len() {
            f(i, j + 1, grid)
        } 
        if j > 0 {
            f(i, j - 1, grid)
        }
        if i + 1 < grid.len() {
            f(i + 1, j, grid)
        }
        if i > 0 {
            f(i - 1, j, grid)
        }
    }
}
```

栈

```rust []
impl Solution {
    pub fn num_islands(mut grid: Vec<Vec<char>>) -> i32 {
        if grid.len() == 0 || grid[0].len() == 0 {
            return 0
        }
        let mut ans = 0;
        let mut s = Vec::new();
        for x in 0..grid.len() {
            for y in 0..grid[x].len() {
                if grid[x][y] == '1'{
                    s.push((x, y));
                    while let Some((i, j)) = s.pop() {
                        if grid[i][j] == '1' {
                            grid[i][j] = '0';
                            if j + 1 < grid[0].len() {
                                s.push((i, j + 1))
                            } 
                            if j > 0 {
                                s.push((i, j - 1))
                            }
                            if i + 1 < grid.len() {
                                s.push((i + 1, j))
                            }
                            if i > 0 {
                                s.push((i - 1, j))
                            }
                        }
                    }
                    ans += 1;
                }
            }
        }
        ans
    }
}
```
