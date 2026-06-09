使用队列，记录栈，当前“优势”党派的人数，遇到自己党派的+1，并入队列继续循环；遇到对方党派的，使用权力优势变少，对方党派被杀死，不再进入序列。当有一方数量为0时停止循环

```
use std::collections::VecDeque;

impl Solution {
    pub fn predict_party_victory(senate: String) -> String {
        let mut queue: VecDeque<bool> = senate.chars().map(|senator| senator == 'R').collect();
        let r_count = queue.iter().filter(|&&is_r| is_r).count();
        let d_count = senate.len() - r_count;
        let mut count = [r_count, d_count];
        let mut curr_balance = 0;
        while count[0] != 0 && count[1] != 0 {
          let curr_senator_is_r = queue.pop_front().unwrap();
          let curr = if curr_senator_is_r { 1 } else { -1 };
          if curr_balance * curr >= 0 {
            queue.push_back(curr_senator_is_r);
          } else { // one omitted
            count[if curr_senator_is_r { 0 } else {1}] -= 1;
          }
          curr_balance += curr;
        }
        // println!("{:?}, {} {}", queue, r_count, d_count);
        (if count[1] == 0 { "Radiant" } else { "Dire" }).to_string()
    }
}
```
