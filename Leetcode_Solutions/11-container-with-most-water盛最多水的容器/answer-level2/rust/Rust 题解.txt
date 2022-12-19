
### 代码

```rust
impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let mut left_point: i32 = 0;
        let mut right_point: i32 = (Vec::len(&height)-1) as i32;
        let mut max_value: i32 = 0;
        while left_point < right_point {
            let mut temp_value = 0;
            let left_height = height[left_point as usize];
            let right_height = height[right_point as usize];
            if left_height > right_height {
                temp_value = right_height*(right_point-left_point);   
                right_point -= 1;
            } else {
                temp_value = left_height*(right_point-left_point);
                left_point += 1;
            }
            if temp_value > max_value {
                    max_value = temp_value;
            }
        }
        max_value
    }
}
```