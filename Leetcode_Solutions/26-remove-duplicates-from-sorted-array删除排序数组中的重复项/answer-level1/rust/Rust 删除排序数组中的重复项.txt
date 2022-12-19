```rust
impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let mut index: usize = 0;
        if nums.len() < 1 {
            return index as i32;
        }
        for i in 1..nums.len() {
            if nums[index] != nums[i] {
                index += 1;
                nums[index] = nums[i];
            }
        }
        return (index + 1) as i32;
    }
}
```
