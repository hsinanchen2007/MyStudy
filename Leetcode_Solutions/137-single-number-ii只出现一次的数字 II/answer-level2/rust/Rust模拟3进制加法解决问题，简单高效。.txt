```Rust
impl Solution {
    // 在每个bit模拟3进制加法
    // mean (once, twice)
    // 0    (0, 0)
    // 1    (1, 0)
    // 2    (1, 1)
    pub fn single_number(nums: Vec<i32>) -> i32 {
        nums.iter()
            .fold((0, 0), |(once, twice), num| {
                (
                    (once | twice | num) & !(once & twice & num),
                    once & (twice ^ num),
                )
            })
            .0
    }
}

```
