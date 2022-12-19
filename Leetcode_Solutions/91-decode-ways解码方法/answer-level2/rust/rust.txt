### 解题思路


### 代码

```rust
impl Solution {
    pub fn num_decodings(s: String) -> i32 {
        if s.trim().len() == 0 {
            return 0;
        }
        let chars = s.chars().collect::<Vec<char>>();
        let mut dp = vec![0; chars.len()+1];
        //初始化条件
        dp[0] = 1;

        //状态转移方程 f(n) = f(n-1) + f(n-2)
        for i in 1..=chars.len() {
            let d = chars[i-1].to_digit(10).unwrap();
            if d>=1 && d<=9 {
                dp[i] += dp[i-1];
            }
            if i>=2 {
                let d = chars[i-2].to_digit(10).unwrap()*10 + d;
                if d>=10 && d<=26 {
                    dp[i] += dp[i-2];
                }
            }
        }
        dp[chars.len()]
    }
}
```