```
impl Solution {
    pub fn game_of_life(board: &mut Vec<Vec<i32>>) {
        let pos = [(-1,-1),(-1,0),(1,-1),(1,0),(1,1),(0,1),(-1,1),(0,-1)];
        let mut cal = board.clone();
        for (i,m) in cal.iter().enumerate(){
            for (j,n) in m.iter().enumerate(){
                let mut live = 0;
                for p in pos.iter(){
                    let x:i32 = i as i32 + p.0;
                    let y:i32 = j as i32 + p.1;
                    if x < 0 || y < 0 || x >= cal.len() as i32 || y >= m.len() as i32 {
                        continue;
                    }
                    if cal[x as usize][y as usize] == 1 {
                        live += 1;
                    }
                }

                if *n == 1 {
                    if live < 2 || live > 3{
                        board[i][j] = 0;
                    } 
                }else{
                    if live == 3{
                        board[i][j] = 1;
                    }
                }
            }
        }

    }
}
```
