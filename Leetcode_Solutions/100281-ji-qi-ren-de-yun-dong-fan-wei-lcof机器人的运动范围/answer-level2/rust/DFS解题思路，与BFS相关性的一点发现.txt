### 解题思路
DFS的解题思路,具体见注释。

DFS使用栈进行遍历，如果想要使用BFS，则在本题使用栈的地方使用队列即可按照广度进行遍历，不得不说数据结构很多时候都有神奇的力量

### 代码

```rust
impl Solution {
    pub fn moving_count(m: i32, n: i32, k: i32) -> i32 {
        let mut accessible: Vec<Vec<i32>> = vec![vec![0;n as usize];m as usize];
        // get all the accessible data of the map, 1 is ok, 0 is not accessible,2 for later means actually can walk to
        for i in 0..m {
            for j in 0..n {
                let sum = i % 10 + (i / 10) % 10 + i/100 + j % 10 + (j / 10) % 10 + j / 100;
                if sum <= k {
                    accessible[i as usize][j as usize] = 1;
                }
            }
        }
        // push the [0,0] as start node, for [0,0] counted here ,set count to 1 and the accessible to 2
        let mut currents: Vec<Vec<i32>> = Vec::new();
        let mut count = 1;
        accessible[0][0] = 2;
        currents.push(vec![0,0]);
        // loop to find the nodes accessible,find new node just push it to stack
        loop {
            if currents.len() == 0 {
                break;
            }
            let current = currents.pop().unwrap();
            if Self::change_block(&(current[0] + 1),&current[1],&mut accessible) {
                currents.push(vec![current[0] + 1,current[1]]);
                count = count + 1;
            }
            if Self::change_block(&(current[0] - 1),&current[1],&mut accessible) {
                currents.push(vec![current[0] - 1,current[1]]);
                count = count + 1;
            }
            if Self::change_block(&current[0],&(current[1] + 1),&mut accessible) {
                currents.push(vec![current[0],current[1] + 1]);
                count = count + 1;
            }
            if Self::change_block(&current[0],&(current[1] - 1),&mut accessible) {
                currents.push(vec![current[0],current[1] - 1]);
                count = count + 1;
            }
        }
        count
    }
    // judge if the node is new accessible node ,if so ,change accessoble to 2 and return true
    pub fn change_block(x: &i32,y: &i32, grid: &mut Vec<Vec<i32>>) -> bool {
        
        if *x >= 0 && *y >= 0 && *x < grid.len() as i32 && *y < grid[0].len() as i32 && grid[*x as usize][*y as usize] == 1 {
            grid[*x as usize][*y as usize] = 2;
            return true;
        }
        false

    }
}
```