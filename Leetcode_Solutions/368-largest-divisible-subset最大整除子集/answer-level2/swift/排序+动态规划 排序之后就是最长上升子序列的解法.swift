排序之后 如果 i<j<k 如果 num[j] % num[i] == 0 而且 num[k] % num[j] == 0 那么 num[k] % num[i]必然也是0 那么这个问题就转换成了最长上升子序列

```
class Solution {
    func largestDivisibleSubset(_ nums: [Int]) -> [Int] {
        let len = nums.count
        if len <= 1 {
            return nums
        }
        var res = [Int]()
        var maxLen = 0
        let sorted = nums.sorted()
        var dp = Array(repeating: 1, count: len)
        for i in 1 ..< len {
            var tmp = [Int]()
            for j in 0 ..< i {
                if sorted[i] % sorted[j] == 0 {
                    if dp[i] < dp[j] + 1 {
                        tmp.append(sorted[j])
                        dp[i] = dp[j] + 1
                    }
                }
            }
            tmp.append(sorted[i])
            if maxLen < dp[i] {
                res = Array(tmp)
                maxLen = dp[i]
            }
        }
        return res
    }
}
```