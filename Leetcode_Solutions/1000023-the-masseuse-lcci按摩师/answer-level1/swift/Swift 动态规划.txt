### 解题思路
dp结题的套路
1.dp状态： 到第i个预约，总预约时间最长。

2.dp方程：到第i个预约的时候，可以选择预约或者不预约
dp[i][0] = max(dp[i - 1][1], dp[i - 1][0])
dp[i][1] = dp[i - 1][0] + nums[i]

3.初始值： 
dp[0][0] = 0
dp[0][1] = nums.first!
### 代码

```swift
class Solution {
 func massage(_ nums: [Int]) -> Int {
    let  count = nums.count
    if count < 2 {
        return nums.reduce(0, +)
    }
    var  dp = Array(repeating: Array(repeating: 0, count: 2), count: count)
    dp[0][0] = 0
    dp[0][1] = nums.first!
    
    for i in 1 ..< count {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][0])
        dp[i][1] = dp[i - 1][0] + nums[i]
    }
    
    return max(dp[count - 1][0], dp[count - 1][1])
 }
}
```