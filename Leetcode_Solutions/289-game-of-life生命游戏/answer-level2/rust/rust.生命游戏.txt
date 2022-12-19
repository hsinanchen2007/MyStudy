### 解题思路
此处撰写解题思路

### 代码

```rust
impl Solution {
    pub fn game_of_life(board: &mut Vec<Vec<i32>>) {
        let direction=vec![(0,1),(0,-1),(1,0),(-1,0),(1,1),(1,-1),(-1,1),(-1,-1)];
        if board.len() == 0 {
            return;
        }
        let m = board.len();
        let n = board[0].len();
        for i in 0..m{
            for j in 0..n{
                let mut cnt = 0;
                for (dx,dy) in &direction{
                    let (x,y) = (i as i32 + dx, j as i32 + dy);
                    if(x<0 || x>=m as i32  || y<0 || y>=n as i32){
                        continue;
                    }
                    cnt += board[x as usize][y as usize] & 1;
                }
                if((board[i][j] & 1) > 0){
                    if(cnt>=2 && cnt<=3){
                        board[i][j]=0b11;
                    }
                }else if(cnt == 3){
                    board[i][j] = 0b10;
                }
            }
        }
        for i in 0..m{
            for j in 0..n{
                board[i][j]>>=1;
            }
        }
    }
}
```