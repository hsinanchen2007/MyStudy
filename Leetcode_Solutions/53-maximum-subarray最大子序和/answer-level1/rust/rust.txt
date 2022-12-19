### 解题思路
动态规划

### 代码

```rust
impl Solution {
    //假设Fin为最大的子序列和，则要么Fn最大要么F(n-1) + Fn最大
    //如果是F(n-1) + Fn较大则有F(n-1) + Fn > Fn
    //则 F(n-1) > 0
    //状态转移方程 Fn = Max(F(n-1)+Fn, Fn)
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        //最大和
        let mut max_sum = i32::min_value(); 
        //当前和
        let mut curr_sum = 0; 
        for n in nums {
            //状态转移方程
            curr_sum = n.max(curr_sum+n);
            max_sum = max_sum.max(curr_sum);
        }
        max_sum
    }
}
```