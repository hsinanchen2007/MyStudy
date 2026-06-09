
### 代码

```swift
class Solution {
    func findNumberOfLIS(_ nums: [Int]) -> Int {
        let n = nums.count 
        if n == 0 {
            return 0
        }
        var res = 0
        var maxValue = 0
         // 以nums[i] 结尾的最长的递增子序列的数量
        var counts = [Int](repeating: 1, count: n)
        // 以nums[i] 结尾的最长的递增子序列的长度
        var lengths = [Int](repeating: 1, count: n) 
        for i in 0..<n {
            for j in 0..<i {
                // nums数组中的最后一个元素 > 子序列(短的)数组的最后一个元素
                if nums[i] > nums[j] {
                    // 子序列的长度 + 1 > 当前数组的长度: 表示找到了新的解
                    if lengths[j] + 1 > lengths[i] {
                        lengths[i] = lengths[j] + 1
                        counts[i] = counts[j]
                    } else if (lengths[j] + 1 == lengths[i]) {
                        counts[i] += counts[j]
                    }
                }
            }
            maxValue = max(maxValue, lengths[i])
        }
        for i in 0..<n {
            if maxValue == lengths[i] {
                res += counts[i]
            }
         }
        return res
    }
}
```