```
impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> i32 {
        let (mut cnt, len, mut res) = (0, nums.len(), nums[0]);
        for i in 0..len {
            cnt += if res == nums[i] { 1 } else { -1 };
            if cnt < 0 {
                res = nums[i];
                cnt = 0;
            }
        }
        res
    }
}
```
![image.png](https://pic.leetcode-cn.com/6396e625709aec0c8fd98d328d2f664ba6ceac03f385a9f2a7e294f0b820ac04-image.png)
