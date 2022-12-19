```
impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        let len = nums.len();
        if(len<1){
            return 0;
        }
        let (mut left, mut right) = (0, len - 1);
        while left < len {
            // println!("left: {}, right: {}, nums: {:?}", left, right, nums);
            while(nums[right] == val){
                if(right == 0){
                    return 0;
                }
                right -= 1;
            }
            if(nums[left] == val){
                nums[left] = nums[right];
                nums[right] = val;
                right -= 1;
                while(nums[right] == val){
                    right -= 1;
                }
            }
            if(left == right) {
                break;
            }
            left += 1;
        }
        (left + 1) as i32
    }
}
```
![image.png](https://pic.leetcode-cn.com/8f0a1beec487fd90bc7dc7c1d9985baf02ab6987595ddb0b952367262e4c4485-image.png)
