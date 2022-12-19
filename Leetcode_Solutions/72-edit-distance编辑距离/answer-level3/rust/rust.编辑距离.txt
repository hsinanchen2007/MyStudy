### 解题思路
此处撰写解题思路

### 代码

```rust
impl Solution {
    pub fn min_distance(word1: String, word2: String) -> i32 {
        let n = word1.len();
        let m = word2.len();

        if n*m ==0 {
            return (n+m) as i32;
        }
        let mut dp:Vec<Vec<usize>>=vec![vec![0;m+1];n+1];
        for i in 0..n+1{
            dp[i][0] = i;
        }
        for j in 0..m+1{
            dp[0][j] = j;
        }

        let bw1=word1.into_bytes();
        let bw2=word2.into_bytes();

        for i in 1..n+1{
            for j in 1..m+1{
                if bw1[i-1]!=bw2[j-1]{
                    dp[i][j]=(dp[i-1][j]+1).min(dp[i][j-1]+1).min(dp[i-1][j-1]+1);
                }else{
                    dp[i][j]=(dp[i-1][j]+1).min(dp[i][j-1]+1).min(dp[i-1][j-1]);
                }
            }
        }
        dp[n][m] as i32
    }
}

```