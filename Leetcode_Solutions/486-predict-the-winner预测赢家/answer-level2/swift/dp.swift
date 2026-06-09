
dp[i][j]在i到j区间选手1的分数减去选手2的分。
求dp[i][j]: 
* 选手1如果先选num[i]，那么他们的差值就应该是num[i]加上i+1到j区间的情况，在这里因为选手1选过了，所以i+1到j应该是选手2先选(反过来了)，那这个区间差值就应该是-dp[i+1][j]，所以这个情况下的结果就是num[i]-dp[i+1][j]
* 同理选手1如果先选了[j]，那么这个情况下的差值应该是num[j]-dp[i][j-1]
* 所以综合这两种情况，方程就是`dp[i][j] = max(num[i]-dp[i+1][j], num[j]-dp[i][j-1])`

```swift
class Solution {
    func PredictTheWinner(_ nums: [Int]) -> Bool {
        let n = nums.count
        if nums.count % 2 == 0 || n == 1 {
            return true
        }
        
        var dp:[[Int]] = Array(repeating: Array(repeating: 0, count: n), count: n)
        for i in stride(from: n-1, through: 0, by: -1) {
            for j in i...n-1 {
                if i == j {
                    dp[i][j] = nums[i]
                }else{
                    dp[i][j] = max(nums[i] - dp[i+1][j],nums[j] - dp[i][j-1])
                }
            }
        }
        return dp[0][n-1] >= 0
    }
}
```