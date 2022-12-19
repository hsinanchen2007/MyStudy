### 解题思路
没写，懒得写

### 代码

```rust
use std::cmp::max;
impl Solution {
    pub fn trap(height: Vec<i32>) -> i32 {
        if height.len() < 3 {
            return 0;
        }

        let (mut left, mut right, mut depth, mut result) = (0, height.len() - 1, std::i32::MIN, 0);

        while left < right {
            let p;
            if height[left] < height[right] {
                p = left;
                left += 1;
            } else {
                p = right;
                right -= 1;
            }
            depth = max(depth, height[p]);
            if depth > height[p] {
                result += depth - height[p];
            }
        }
        result
    }
}
```