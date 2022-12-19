### 解题思路
此处撰写解题思路

### 代码

```rust
impl Solution {
    pub fn num_rook_captures(board: Vec<Vec<char>>) -> i32 {
        let dx:Vec<i32>=vec![ -1, 1,  0, 0 ];
        let dy:Vec<i32>=vec![  0, 0, -1, 1 ];
        for i in 0..8{
            for j in 0..8{
                if board[i][j] == 'R' {
                    let mut res = 0;
                    for k in 0..4{
                        let mut x = i as i32;
                        let mut y = j as i32;
                        loop{
                            x += dx[k];
                            y += dy[k];
                            if x<0 || x>=8 || y<0 || y>=8 || board[x as usize][y as usize] == 'B'{
                                break;
                            }
                            if board[x as usize][y as usize] == 'p'{
                                res+=1;
                                break;
                            }
                        }
                    }
                    return res;
                }
            }
        }
        return 0;
    }
}

```