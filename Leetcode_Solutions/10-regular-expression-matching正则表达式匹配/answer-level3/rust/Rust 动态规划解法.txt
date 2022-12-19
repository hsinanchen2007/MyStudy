### 代码

```rust
impl Solution {
    pub fn is_match(s: String, p: String) -> bool {
        
        let p_chars: Vec<char> = p.chars().collect();

        let s_chars: Vec<char> = s.chars().collect();
        let mut dp: Vec<Vec<bool>> = vec![vec![false; p_chars.len() + 1]; s_chars.len() + 1];
        dp[0][0] = true;
        for i in 0..p_chars.len() {
            if p_chars[i] == '*' {
                dp[0][i + 1] = dp[0][i - 1];
            } else {
                dp[0][i + 1] = false;
            }
        }
        for i in 1..p_chars.len() + 1 {
            for j in 1..s_chars.len() + 1 {
                if p_chars[i - 1] == s_chars[j - 1] || p_chars[i - 1] == '.' {
                    dp[j][i] = dp[j - 1][i - 1];
                } else {
                    if p_chars[i - 1] == '*' {
                        if p_chars[i - 2] == s_chars[j - 1] || p_chars[i - 2] == '.'{
                            dp[j][i] = dp[j - 1][i] || dp[j][i - 2];
                        } else {
                            dp[j][i] = dp[j][i - 2];
                        }
                    } else {
                        continue;
                    }
                }
            }
        }

        dp[s_chars.len()][p_chars.len()]
    }
}
```