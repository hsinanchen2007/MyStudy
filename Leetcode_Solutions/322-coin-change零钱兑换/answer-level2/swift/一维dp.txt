### 解题思路
 一维dp
dp[i] 保存 总金额i时需要的硬币数
dp[i] = min(dp[i - coins[j]] + 1)

### 代码

```swift
class Solution {
    func coinChange(_ coins: [Int], _ amount: Int) -> Int {
        var dp = [Int](repeating: 0, count: amount + 1)
        
        if amount == 0 {
            return 0
        }
        
        for i in 1...amount {
            
    //        let min = coins.map{i - $0} //去掉一个硬币后的总金额
    //            .filter{$0 >= 0} // 剔除小于0的总金额
    //            .filter{dp[$0] != -1} // 剔除无法组合的总金额
    //            .map{dp[$0] + 1}.min() // 最小硬币数
            
            var cases:[Int] = []
            for coin in coins {
                if (i-coin) >= 0 && dp[i-coin] != -1 {
                    cases.append(dp[i-coin] + 1)
                }
            }
            
            dp[i] = cases.isEmpty ? -1 : cases.min()!
        }
        return dp[amount]
    }
}
```