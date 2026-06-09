```
impl Solution {
    pub fn pivot_index(nums: Vec<i32>) -> i32 {
        let sum: i32 = nums.iter().sum();
        let mut l = 0;
        for i in 0..nums.len(){
            if (sum - l - nums[i] == l){
                return i as i32;
            }
            l += nums[i];
        }
        return -1;
    }
}
```
