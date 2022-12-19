
```
impl Solution {
    fn allow(v: &mut Vec<i32>, num: i32) {
        v[num as usize - 1] = 1;
    }
    fn disallow(v: &mut Vec<i32>, num: i32) {
        v[num as usize - 1] = 0;
    }
    fn check_allow(v: &Vec<i32>, num: i32) -> bool {
        return v[num as usize - 1] == 0;
    }
    fn pick_allows(v: &Vec<i32>) -> Vec<i32> {
        let mut ret = vec![];
        for i in 0 .. v.len() {
            if v[i] == 0 {
                ret.push(i as i32 + 1);
            }
        }
        ret
    }

    fn backtrack(board: &mut Vec<Vec<char>>, rows: &mut Vec<Vec<i32>>, cols: &mut Vec<Vec<i32>>, boxs: &mut Vec<Vec<i32>>, mut i: usize, mut j: usize) -> bool {
        if i == 8 && j == 8 {
            if board[i][j] != '.' {
                return true;
            } else {
                let trys = Self::pick_allows(&rows[i]);  
                for idx in 0..trys.len() {
                    let picked = trys[idx];
                    if Self::check_allow(&cols[j], picked) && 
                        Self::check_allow(&boxs[(i / 3) * 3 + j / 3], picked) {
                            board[i][j] = std::char::from_digit(picked as u32, 10).unwrap();
                            return true;
                    }
                }
                return false;
            }
        }
        if board[i][j] != '.' {
            j += 1;
            if j == 9 {
                i += 1;
                j = 0;
            }
            return Self::backtrack(board, rows, cols, boxs, i, j);
        } else {
            let trys = Self::pick_allows(&rows[i]); 
            for idx in 0..trys.len() {
                let picked = trys[idx];
                if Self::check_allow(&cols[j], picked) && 
                    Self::check_allow(&boxs[(i / 3) * 3 + j / 3], picked) {
                        Self::allow(&mut rows[i], picked);
                        Self::allow(&mut cols[j], picked);
                        Self::allow(&mut boxs[(i / 3) * 3 + j / 3], picked);

                        board[i][j] = std::char::from_digit(picked as u32, 10).unwrap();

                        let mut next_j = j + 1;
                        let mut next_i = i;
                        if next_j == 9 {
                            next_i += 1;
                            next_j = 0;
                        }
                        let next_ret = Self::backtrack(board, rows, cols, boxs, next_i, next_j);

                        if next_ret == false {
                            Self::disallow(&mut rows[i], picked);
                            Self::disallow(&mut cols[j], picked);
                            Self::disallow(&mut boxs[(i / 3) * 3 + j / 3], picked);
                            board[i][j] = '.';
                            
                        } else {
                            break;
                        }
                }
            }
            return board[i][j] != '.';
        }

    }
    pub fn solve_sudoku(board: &mut Vec<Vec<char>>) {
        let mut rows = vec![vec![0; 9]; 9];
        let mut cols = vec![vec![0; 9]; 9];
        let mut boxs = vec![vec![0; 9]; 9];

        for (i, r) in board.iter().enumerate() {
            for (j, v) in r.iter().enumerate() {
                if let Some(num) = v.to_digit(10) {
                    let num = num as usize - 1;
                    rows[i][num] = 1;
                    cols[j][num] = 1;
                    boxs[(i / 3) * 3 + j / 3][num] = 1;
                }
            }
        }
        Self::backtrack(board, &mut rows, &mut cols, &mut boxs, 0, 0);
    }
}
```
