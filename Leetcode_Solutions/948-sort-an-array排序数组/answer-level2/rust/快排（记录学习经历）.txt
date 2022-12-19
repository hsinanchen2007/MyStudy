### 解题思路
简单的快排

### 代码

```rust
impl Solution {
    pub fn sort_array(nums: Vec<i32>) -> Vec<i32> {
        let mut vec_result = nums.to_owned();
        //vec_result.sort();
        vec_result = Self::quick_sort(nums);
        vec_result
    }
    pub fn quick_sort(nums: Vec<i32>) -> Vec<i32> {
        if nums.len() <= 1 {
            return nums;
        }
        let mut vec1: Vec<i32> = Vec::new();
        let mut vec2: Vec<i32> = Vec::new();
        for  i in 1..nums.len() {
            if nums[i] >= nums[0] {
                vec2.push(nums[i]);
            } else {
                vec1.push(nums[i]);
            }
        }
        let mut result = Self::quick_sort(vec1);
        result.push(nums[0]);
        result.append(&mut Self::quick_sort(vec2));
        
        //println!("{:?}",result);
        result
    }
}
```