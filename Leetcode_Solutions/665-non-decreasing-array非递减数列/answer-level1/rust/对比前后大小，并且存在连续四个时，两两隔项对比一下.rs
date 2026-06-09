```
impl Solution {
    pub fn check_possibility(nums: Vec<i32>) -> bool {
        let mut count = 0;
        for i in 0..nums.len()-1 {
            if nums[i] > nums[i+1] {        // 有异常情况
                if count > 0 {
                    return false;           // 多次异常已经不可能了   
                }
                if nums.get(i-1) != None && nums.get(i+2) != None {         // [3,4,2,5] 这种情况虽然只有一次异常，但是已经锁死4,2这两个元素，让它们无法调整了。
                    if nums[i-1] > nums[i+1] && nums[i] > nums[i+2] {
                        return false;
                    }
                }
                count += 1;
            }
        }
        true
    }
}
```
