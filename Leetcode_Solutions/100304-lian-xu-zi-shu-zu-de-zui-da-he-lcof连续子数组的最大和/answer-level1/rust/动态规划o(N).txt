```
impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        if (nums.len() == 0) {
            return 0;
        }
        let mut max:i32 = i32::min_value();
        let mut imax:i32 = 0;
        
        for i in 0..nums.len(){
            imax = std::cmp::max(*&nums[i], *&nums[i]+imax);
            max = std::cmp::max(max, imax);
        }
        max
    }
}
```