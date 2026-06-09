### 解题思路
此处撰写解题思路

### 代码

```rust
impl Solution {
    //动态规划
    pub fn massage(nums: Vec<i32>) -> i32 {
        if nums.is_empty() {return 0}
        let len = nums.len();
        let mut dp = vec![(0,0);len];
        dp[0] = (nums[0],0);//(选了,没选)
        for i in 1..len{
            dp[i] = (dp[i-1].1+nums[i],std::cmp::max(dp[i-1].0,dp[i-1].1));
        }
        std::cmp::max(dp[len-1].0,dp[len-1].1)
    }

    //递归
    pub fn massage1(nums: Vec<i32>) -> i32 {
        if nums.is_empty() {return 0}
        Self::help(0,&nums)
    }

    fn help(idx:usize,nums:&Vec<i32>)->i32{
        if idx < nums.len()-1{
            std::cmp::max(nums[idx]+Self::help(idx+2,&nums),Self::help(idx+1,nums))
        }
        else if idx == nums.len()-1{
            nums[idx]
        }
        else{
            0
        }
    }
}
```