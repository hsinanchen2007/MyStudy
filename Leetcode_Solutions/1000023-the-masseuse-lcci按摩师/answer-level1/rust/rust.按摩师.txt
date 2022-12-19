### 解题思路
此处撰写解题思路

### 代码

```rust
impl Solution {
    pub fn massage(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        if(n==0) {
            return 0;
        }
        let mut dp0 = 0;
        let mut dp1 = nums[0];

        for i in 1..n{
            let tdp0 = dp0.max(dp1);
            let tdp1 = dp0 + nums[i];
            dp0 = tdp0;
            dp1 = tdp1;
        }
        dp0.max(dp1)
    }
}


```