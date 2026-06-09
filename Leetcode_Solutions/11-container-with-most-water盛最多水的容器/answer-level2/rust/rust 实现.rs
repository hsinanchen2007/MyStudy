### 解题思路
此处撰写解题思路

### 代码

```rust
impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
    let mut area = 0;
    let mut left = 0;
    let mut right = (height.len() - 1) as i32;

    while left < right {
        let left_height = height[left as usize];
        let right_height = height[right as usize];
        let mut temp = 0;
        if left_height > right_height {
            temp = right_height;
        }else {
            temp = left_height;
        }
        let tempArea = temp * (right - left);
        
        if left_height >  right_height {
            right = right -1;
        }else {
            left = left + 1;
        }

        if tempArea > area{
            area = tempArea;
        }
    }
    area
    }
}
```