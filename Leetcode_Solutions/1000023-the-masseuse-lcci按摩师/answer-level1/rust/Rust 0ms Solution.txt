### 解题思路
dp
num[i] = max(num[i-1],num[i-2]+num[i])

### 代码

```rust
use std::cmp::max;
impl Solution {
pub fn massage(mut nums: Vec<i32>) -> i32 {
    if nums.len() >= 2 {
        nums[1] = nums[0].max(nums[1]);
    }
    for i in 2..nums.len() {
        nums[i] = max(nums[i-1],nums[i-2] + nums[i]);
    }
    nums.last().map_or(0, |&val| val)
}
}
```