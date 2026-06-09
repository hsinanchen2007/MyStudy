### 解题思路
此处撰写解题思路

### 代码

```rust
impl Solution {
    pub fn find_min_step(board: String, hand: String) -> i32 {
        //RYBGW 只有这五种情况,分别映射为0,1,2,3,4 简单起见
        let board = Self::map_board(board);
        let hand = Self::map_hand(hand);
        //        println!("board={:?}", board);
        //        println!("hand={:?}", hand);
        let mut min_step = std::i32::MAX;
        for i in 0..board.len() {
            let c = Self::try_step(i, board.clone(), hand.clone(), 0);
            if c > 0 && min_step > c {
                min_step = c;
            }
            //            println!("try c={},i={},min_step={}", c, i, min_step);
        }
        if min_step == std::i32::MAX {
            min_step = -1;
        }
        min_step
    }
    fn try_step(start: usize, mut board: Vec<(i32, i32)>, mut hand: [i32; 5], current: i32) -> i32 {
        //        println!("try start={}, current={}", start, current);
        //        println!("board={:?},hand={:?}", board, hand);

        let pick = board[start];
        let need = 3 - pick.1;
        if hand[pick.0 as usize] < need {
            return -1;
        }
        //可以移除一个了,
        Self::remove_and_merge(&mut board, start);
        hand[pick.0 as usize] -= need;
        if board.len() == 0 {
            println!("found={}", current + need);
            return current + need; //找到了一种方法,
        }
        let mut current_min_step = std::i32::MAX;
        for i in 0..board.len() {
            let c = Self::try_step(i, board.clone(), hand.clone(), current + need);
            if c > 0 && current_min_step > c {
                current_min_step = c;
            }
        }
        if current_min_step != std::i32::MAX {
            return current_min_step;
        }
        -1
    }
    fn remove_and_merge(board: &mut Vec<(i32, i32)>, i: usize) {
        board.remove(i);
        if board.len() > i && i >= 1 {
            //移除的是中间的某个数值,如果移除的是0,或者最后一个,肯定不会合并
            let mut left = board[i - 1];
            let right = board[i];
            if left.0 == right.0 {
                left.1 += right.1;
                board.remove(i);
                if left.1 >= 3 {
                    Self::remove_and_merge(board, i - 1);
                } else {
                    board[i - 1] = left;
                }
            }
        }
    }
    //每个字符以及其出现的次数
    fn map_board(board: String) -> Vec<(i32, i32)> {
        let mut v = Vec::new();
        let mut last = -1;
        let mut last_count = -1;
        for i in board.as_bytes() {
            let c = match *i as char {
                'R' => 0,
                'Y' => 1,
                'B' => 2,
                'G' => 3,
                'W' => 4,
                _ => panic!("not possible"),
            };
            if c != last {
                if last_count > 0 {
                    v.push((last, last_count));
                }
                last = c;
                last_count = 1;
            } else {
                last_count += 1;
            }
        }
        if last_count > 0 {
            v.push((last, last_count));
        }
        v
    }
    fn map_hand(hand: String) -> [i32; 5] {
        let mut v = [0; 5];
        for i in hand.as_bytes() {
            let c = match *i as char {
                'R' => 0,
                'Y' => 1,
                'B' => 2,
                'G' => 3,
                'W' => 4,
                _ => panic!("not possible"),
            };
            v[c] += 1;
        }
        v
    }
}
```