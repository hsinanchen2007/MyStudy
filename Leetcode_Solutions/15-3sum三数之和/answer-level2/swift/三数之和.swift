```swift []
class Solution {
  func threeSum(_ nums: [Int]) -> [[Int]] {
        let sortNum = nums.sorted()
        var r = [[Int]]()
        for (idx, val) in sortNum.enumerated() {
            // 过滤是关键
            if idx - 1 >= 0, idx - 1 < sortNum.count, sortNum[idx-1] == val {
                continue
            }
            var low = idx + 1
            var high = sortNum.count - 1
            
            while low < high {
                let target = 0 - val
                let sum = sortNum[low] + sortNum[high]
                if sum < target {
                    while low < high, sortNum[low] == sortNum[low+1] {
                        low = low + 1
                    }
                    low = low + 1
                } else if sum > target {
                    while high > low, sortNum[high] == sortNum[high - 1] {
                        high = high - 1
                    }
                    high = high - 1
                } else {
                    r.append([val, sortNum[low], sortNum[high]])
                    while low < high, sortNum[low] == sortNum[low+1] {
                        low = low + 1
                    }
                    low = low + 1
                    while high > low, sortNum[high] == sortNum[high - 1] {
                        high = high - 1
                    }
                    high = high - 1
                }
            }
            
        }
        return r
    }
}
```
