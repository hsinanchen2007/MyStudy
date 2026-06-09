### 解题思路
此处撰写解题思路

### 代码

```rust
use std::cmp::Ordering;
use std::collections::BinaryHeap;

#[derive(Copy, Clone, Eq, PartialEq, Hash)]
struct State {
    v: i32,
    x: i32,
    y: i32
}
// The priority queue depends on `Ord`.
// Explicitly implement the trait so the queue becomes a min-heap
// instead of a max-heap.
impl Ord for State {
    fn cmp(&self, other: &State) -> Ordering {
        // Notice that the we flip the ordering on costs.
        // In case of a tie we compare positions - this step is necessary
        // to make implementations of `PartialEq` and `Ord` consistent.
        other.v.cmp(&self.v)
    }
}
// `PartialOrd` needs to be implemented as well.
impl PartialOrd for State {
    fn partial_cmp(&self, other: &State) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}
impl Solution {
    pub fn max_distance(grid: Vec<Vec<i32>>) -> i32 {
        let n =grid.len();
        let INF = i32::max_value();
        let dx:Vec<i32> = vec![-1,0,1,0];
        let dy:Vec<i32> = vec![0,1,0,-1];
        let mut a = grid;
        let mut d:Vec<Vec<i32>>=vec![vec![INF;n];n];
        let mut pq = BinaryHeap::new();
        //
        for i in 0..n{
            for j in 0..n{
                if a[i][j]==1 {
                    d[i][j]=0;
                    pq.push(State{v:0,x:i as i32,y:j as i32});
                }
            }
        }
        //
        while let Some(State {v,x,y}) = pq.pop(){
            for i in 0..4 {
                let nx = x+dx[i];
                let ny = y+dy[i];
                if nx>=0 && nx<n as i32 && ny>=0 && ny<n as i32 {
                    if(v+1 < d[nx as usize][ny as usize]){
                        d[nx as usize][ny as usize] = v+1;
                        pq.push(State{v:v+1,x:nx,y:ny});
                    }
                }
            }
        }
        //
        let mut ans = -1;
        for i in 0..n{
            for j in 0..n{
                if a[i][j]==0{
                    ans = ans.max(d[i][j]);
                }
            }
        }
        //
        if ans == INF {
            -1
        }else{
            ans
        }
    }
}
```