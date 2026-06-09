### 解题思路
此处撰写解题思路

### 代码

```rust
impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut i = 0;
        let mut j = nums.len()-1;
        let mut res=vec![0;2];
        while i<=j {
            if nums[i]+nums[j]==target{
                return vec![nums[i],nums[j]];
            }
            if nums[i]+nums[j]<target{
                i+=1;
            }
            if nums[i]+nums[j]>target{
                j-=1;
            }
        }
        res
    }
}
```