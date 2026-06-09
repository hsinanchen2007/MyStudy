```rust
impl Solution {
    pub fn smaller_numbers_than_current(nums: Vec<i32>) -> Vec<i32> {
        let mut nums = nums;
        let mut freq = [0;101];
        for x in &nums {
            freq[*x as usize] += 1;
        }
        for ptr in nums.iter_mut() {
            let index = *ptr as usize;
            let mut s = 0;
            for f in &freq[0..index] {
                s += f;
            }
            *ptr = s;
        }
        nums
    }
}
```