### 解题思路
此处撰写解题思路

### 代码

```rust
use std::collections::VecDeque;
impl Solution {
    pub fn get(&self,x:i32)->i32{
        let mut res=0;
        let mut x=x;
        while x!=0{
            res +=  x%10;
            x = x/10;
        }
        res
    }
    pub fn moving_count(m: i32, n: i32, k: i32) -> i32 {
        if k==0{
            return 1;
        }
        let dx=vec![0,1];
        let dy=vec![1,0];
        let mut vis=vec![vec![0;n as usize];m as usize];
        let mut queue:VecDeque<(i32,i32)>=VecDeque::new();
        queue.push_back((0,0));
        vis[0][0]=1;
        let mut ans = 1;
        while let Some((x,y)) = queue.pop_front(){
            for i in 0..2{
                let tx = x + dx[i];
                let ty = y + dy[i];
                let sumtxy = Self.get(tx)+Self.get(ty);
                if tx < 0 || tx >=m || ty <0 || ty>=n || vis[tx as usize][ty as usize]==1 || sumtxy>k {
                    continue
                }else{
                    queue.push_back((tx,ty));
                    vis[tx as usize][ty as usize]=1;
                    ans+=1;
                }
            }
        }
        ans
    }
}
```