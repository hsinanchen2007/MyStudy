### 解题思路
此处撰写解题思路

### 代码

```rust
impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        if nums.is_empty() {
            return 0;
        } else if nums.len() == 1 {
            return 1;
        }
        let mut i = 1;
        let mut j = 0;
        while i < nums.len() {
            if nums[i] == nums[i - 1] {
            } else {
                j += 1;
                nums[j] = nums[i];
            }
            i += 1;
        }
        j as i32 + 1
    }
}
```