### 解题思路
对于每一位, 可以选择接与不接, 但是不能相邻两个都接
所以到当天i截止时的最高收益 = { 今天接 + 前天的最大收益, 昨天的最大收益}
dp[i] = max{ nums[i] + dp[i-2] , dp[i-1]}
### 代码

```swift
class Solution {
    func massage(_ nums: [Int]) -> Int {
        guard nums.count > 2 else {
            return nums.max() ?? 0
        }
        
        
        var dp = [Int](repeating: 0, count: nums.count)
        dp[0] = nums[0]
        dp[1] = max(dp[0], nums[1])
        
        for i in 2..<nums.endIndex {
            dp[i] = max(nums[i] + dp[i-2], dp[i-1])
        }
        
        
        return dp.last!
    }
}
```