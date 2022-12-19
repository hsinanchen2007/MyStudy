### 动态规划

见注释

### 代码

```swift
class Solution {
    func PredictTheWinner(_ nums: [Int]) -> Bool {
        let count = nums.count
        // dp[i][j]表示从nums[i]到nums[j]先手比另一位玩家多的最大分数，
        // 最后返回dp[0][nums.count - 1]是否大于0即可
        // 对于dp[i][j]，如果先手拿了nums[i]，则另一位玩家比先手多dp[i+1][j]，dp[i][j] = nums[i] - dp[i+1][j]
        // 如果先手拿了nums[j]，则另一位玩家比先手多dp[i][j-1]，dp[i][j] = nums[j]-dp[i][j-1]
        var dp = [[Int]](repeating: [Int](repeating: 0, count: count), count: count)
        for i in 0..<count {
            dp[i][i] = nums[i]
        }
        for i in (0..<count).reversed() {
            var j = i + 1
            while j < count {
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1])
                j += 1
            }
        }
        return dp[0][count - 1] >= 0
    }
}
```