为应对 i32 溢出，使用 u64；对从 low 到 high 长度的数值依次检索符合条件的中心对称数。

剪枝条件：

- 当前和 + 1 * pow(10, 当前位) < low
- 当前和 > high
- 最终和 !=0 且 最终和以 0 开头
- 最终和 ==0 且结果中已经有 0

```rust
use std::rc::Rc;
use std::cell::RefCell;

const CENTER_CHAR_SIZE: usize = 3;
const PAIR_CHAR_SIZE: usize = 5;
const CENTER_CHARS: [u64; CENTER_CHAR_SIZE] = [0, 1, 8];
const PAIR_CHARS: [(u64,u64); PAIR_CHAR_SIZE] = [
    (0,0),
    (1,1),
    (6,9),
    (8,8), 
    (9,6)];

impl Solution {
    pub fn strobogrammatic_in_range(
        low: String, 
        high: String) -> i32 {
        let ll = low.len();
        let lh = high.len();
        let low = low.parse().unwrap();
        let high = high.parse().unwrap();
        let res = Rc::new(RefCell::new(
            vec![]
        ));
        for l in ll..=lh {
            let target = if (l & 1)==1 {
                l/2
            } else {
                l/2 - 1
            } as u32;
            Solution::strobogrammatic_in_range_rec(
                low, high, 0, 
                0, target, (l - 1) as u32,
                res.clone()
            );
        }
        let res_b = res.borrow();
        res_b.len() as i32
    }

    pub fn strobogrammatic_in_range_rec(
        low: u64, high: u64,  sum: u64,
        curr: u32, target: u32, all: u32,
        res: Rc<RefCell<Vec<String>>>
    ) {
        if curr<target || 
            ((curr==target) && ((all & 1)==1)) {
            for (a,b) in &PAIR_CHARS {
                let high_order_factor = u64::pow(10, all - curr);
                let low_order_factor = u64::pow(10, curr);
                let new_sum = sum 
                    + (*a) * high_order_factor
                    + (*b) * low_order_factor;
                if new_sum > high || new_sum + high_order_factor <= low  {
                    continue;
                }
                Solution::strobogrammatic_in_range_rec(
                    low, high, new_sum, 
                    curr+1, target, all,
                    res.clone()
                );
            }
        } else if (curr==target) && ((all & 1)==0) {
            for a in &CENTER_CHARS {
                let new_sum = sum 
                    + a * u64::pow(10, all - curr);
                if new_sum > high || new_sum < low  {
                    continue;
                }
                Solution::strobogrammatic_in_range_rec(
                    low, high, new_sum, 
                    curr+1, target, all,
                    res.clone()
                );
            }
        } else if sum==0 || sum>=u64::pow(10, all)  {
            let mut res_bm = res.borrow_mut();
            if sum==0 && !res_bm.is_empty() && res_bm[0]=="0" {
                return;
            }
            res_bm.push(sum.to_string());
        }
    }
}
```