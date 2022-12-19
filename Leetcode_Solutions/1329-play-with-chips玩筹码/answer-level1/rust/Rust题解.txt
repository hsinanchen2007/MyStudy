```Rust
impl Solution {
    pub fn min_cost_to_move_chips(chips: Vec<i32>) -> i32 {
        let odd_cnt = chips.iter().filter(|&x| x % 2 == 1).count();
        odd_cnt.min(chips.len() - odd_cnt) as i32
    }
}
```
[其他题目的Rust题解](https://github.com/fruit-in/LeetCode/blob/master/README_CN.md)
