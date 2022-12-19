### 动态规划
状态转移方程为如下 其中 N表示需要N amout的钱的时候需要的最少coin数量
循环为遍历每一种coin 然后判断加入了这种coin之后兑换[coin,amount] 中需要的最少coin数量。
dp[N] = {
    -1, dn[N] == -1 && dn[N-coin] == -1
    min(dp[N],dn[N-coin] + 1), dn[N] != -1 && dn[N-coin] !=-1
    dp[N-coin],dn[N] == -1 && dn[N - coin] !=-1
}

### 代码
第一次写rust 见谅见谅。。
```rust
impl Solution {
    pub fn coin_change(coins: Vec<i32>, amount: i32) -> i32 {
        let amount= amount as usize;
        let len = amount + 1;
        let coin_types:Vec<usize> = coins.iter().map(|v| *v as usize).collect();
        let mut dp:Vec<i32> = vec![-1;len];
        dp[0] = 0;
        for &coin in coin_types.iter(){
            for i in coin..len{
                 dp[i] = match (dp[i - coin] == -1,dp[i] == -1){
                     (true,_) => dp[i],
                     (false,true) => dp[i - coin] + 1,
                     _ => dp[i].min(dp[i-coin] + 1),
                 }
            }
        }
        dp[amount]
    }
}
```