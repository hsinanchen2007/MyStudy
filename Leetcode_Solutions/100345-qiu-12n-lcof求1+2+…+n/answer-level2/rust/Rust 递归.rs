```rs
impl Solution {
    pub fn sum_nums(n: i32) -> i32 {
        let mut n = n;
        n > 0 && {
            n += Solution::sum_nums(n - 1);
            true
        };
        n
    }
}
```