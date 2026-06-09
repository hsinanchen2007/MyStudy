### 动态规划

### 代码

```swift
class Solution {

     func coinChange(_ coins: [Int], _ amount: Int) -> Int {
        if coins.count == 0{
            return -1
        }
        // dp[i][j] 使用i种硬币达到j的最小数量
        var dp = Array(repeating: amount + 1, count: amount + 1)
        // 0 需要 0的硬币
        dp[0] = 0
        for coin in coins {
            var i = coin
            while i <= amount {
                // 假如: i - coin 合法, 只需要加上当前这一枚硬币即可
                dp[i] = min(dp[i], dp[i - coin] + 1)
                i += 1
            }
        }
        return dp[amount] >= amount + 1 ? -1:dp[amount]
    
    }
}
```

### DFS

### 代码

```swift
class Solution {

     func coinChange(_ coins: [Int], _ amount: Int) -> Int {
       
        // 降序排序
        let sorted_coins = coins.sorted(by: { $0 > $1 })
        // 解
        var res = Int.max
        dfs_coinChange(sorted_coins, 0, amount, 0, &res)
        return res == Int.max ? -1:res;
    }
    // index: 索引
    // amount: 剩余面额
    // count: 当前已经使用的硬币数
    // res: 输出
    func dfs_coinChange( _ coins:[Int], _ index: Int,_ amount: Int, _ count: Int, _ res: inout Int) {
        let coin = coins[index]
           if index == coins.count - 1 {
               if amount % coin == 0 {
                   res = min(res, count + amount / coin)
               }
           } else {
               var k = amount / coin
               while k >= 0 && (count + k) < res {
                   dfs_coinChange(coins, index + 1, amount - k * coin, count + k, &res)
                   k -= 1
               }
         }
       }
}
```

