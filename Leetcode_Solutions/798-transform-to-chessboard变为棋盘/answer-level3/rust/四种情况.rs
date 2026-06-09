可以证明规律：
1. 行和列是正交的，即互不影响。“先移动行，后移动列” 和 “先移动列，后移动行” 是等价的。”先移动列，再移动行，再移动列“等价于”先把列移动完，再移动行“。
2. “交换行i,j，交换行j,k“ 等价于“交换行i,k“

四种情况：
1. 先移动行让行首成 010101... 状态，再移动列让列首成 010101... 状态
2. 先移动行让行首成 010101... 状态，再移动列让列首成 101010... 状态
3. 先移动行让行首成 101010... 状态，再移动列让列首成 010101... 状态
4. 先移动行让行首成 101010... 状态，再移动列让列首成 101010... 状态

分别计算四种情况需要的步数，取最小值

```
impl Solution {
    pub fn moves_to_chessboard(board: Vec<Vec<i32>>) -> i32 {
      // change row to 010, change col to 010
      fn moves_to(board: &Vec<Vec<i32>>, row_sign: i32, col_sign: i32) -> Option<i32> {
        let mut unmatch_row_ids = [vec![], vec![]];
        for idx in 0..board.len() {
          if idx % 2 == 0 {
            if board[idx][0] != row_sign {
              unmatch_row_ids[0].push(idx);
            }
          } else {
            if board[idx][0] == row_sign {
              unmatch_row_ids[1].push(idx);
            }
          }
        }
        if unmatch_row_ids[0].len() != unmatch_row_ids[1].len() {
          return None;
        }
        let mut row_map: Vec<_> = (0..board.len()).collect();
        for (&i, &j) in unmatch_row_ids[0].iter().zip(unmatch_row_ids[1].iter()) {
          row_map[i] = j;
          row_map[j] = i;
        }

        let mut unmatch_col_ids = [vec![], vec![]];
        let first_row = &board[row_map[0]];
        for idx in 0..board.len() {
          if idx % 2 == 0 {
            if first_row[idx] != col_sign {
              unmatch_col_ids[0].push(idx);
            }
          } else {
            if first_row[idx] == col_sign {
              unmatch_col_ids[1].push(idx);
            }
          }
        }
        if unmatch_col_ids[0].len() != unmatch_col_ids[1].len() {
          return None;
        }
        let mut col_map: Vec<_> = (0..board.len()).collect();
        for (&i, &j) in unmatch_col_ids[0].iter().zip(unmatch_col_ids[1].iter()) {
          col_map[i] = j;
          col_map[j] = i;
        }

        // check
        for row_idx in 0..board.len() {
          for col_idx in 0..board.len() {
            let m_row_idx = row_map[row_idx];
            let m_col_idx = col_map[col_idx];
            if (row_idx + col_idx) % 2 == 0 && board[m_row_idx][m_col_idx] != col_sign
            || (row_idx + col_idx) % 2 != 0 && board[m_row_idx][m_col_idx] == col_sign {
              return None;
            }
          }
        }
        Some(unmatch_row_ids[0].len() as i32 + unmatch_col_ids[1].len() as i32)
      }
      match [
        moves_to(&board, 0, 0),
        moves_to(&board, 0, 1),
        moves_to(&board, 1, 0),
        moves_to(&board, 1, 1),
      ].iter().filter_map(|&r| {
        println!("{:?}", r);
        r
      }).min() {
        None => -1,
        Some(val) => val,
      }
    }
}
```
