### 解题思路
Fn = F(n-1) + F(n-2)

### 代码

```rust
impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        let n = (n+1) as usize;
        let mut dp = vec![0; n];
        //初始化
        dp[0] = 1;
        for i in 1..n{
            dp[i] += dp[i-1];
            if i>1 {
                dp[i] += dp[i-2];
            }
        }
        dp[n-1]
    }
}
```