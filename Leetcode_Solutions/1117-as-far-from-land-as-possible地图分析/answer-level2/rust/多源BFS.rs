### 解题思路
过程看起来像病毒的传播😓
直接在图上操作感觉没有队列好用
感觉这执行结果的计算有问题？写得再差都有惊喜的100%？
### 代码

```rust
impl Solution {
    pub fn max_distance(grid: Vec<Vec<i32>>) -> i32 {
        let len = grid.len();
        let t = grid.iter().map(|x| x.iter().sum::<i32>()).sum::<i32>();
        if t == 0 || t as usize == len * len {
            return -1;
        }
        let mut grid = grid;
        let mut virus = 2;
        loop {
            let days = virus - 1;
            let mut over_flag = true;
            for j in 0..len {
                for i in 0..len {
                    if grid[j][i] == days {
                        if Solution::infected_virus(&mut grid, virus, (j, i)) {
                            over_flag = false;
                        }
                    }
                }
            }
            if over_flag {
                return virus - 2;
            }
            virus += 1;
        }
    }

    fn infected_virus(grid: &mut Vec<Vec<i32>>, virus: i32, (y, x): (usize, usize)) -> bool {
        let mut flag = false;
        if let Some(e) = grid[y].get_mut(x + 1) {
            if *e == 0 {
                *e = virus;
                flag = true;
            }
        }
        if x > 0 {
            let e = &mut grid[y][x - 1];
            if *e == 0 {
                *e = virus;
                flag = true;
            }
        }
        if let Some(e) = grid.get_mut(y + 1) {
            if (*e)[x] == 0 {
                (*e)[x] = virus;
                flag = true;
            }
        }
        if y > 0 {
            let e = &mut grid[y - 1][x];
            if *e == 0 {
                *e = virus;
                flag = true;
            }
        }
        flag
    }
}
```