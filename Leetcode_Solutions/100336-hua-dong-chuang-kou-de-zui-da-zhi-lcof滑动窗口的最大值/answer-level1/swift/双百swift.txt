### 解题思路
每次滑动的时候记录本次窗口最大值，最大值所在下标，以及本次窗口的范围下标，下次滑动时候根据上次的最大值下标是否在本次滑动范围内，如果在只需要比较上次的滑动窗口的下标和本地滑动窗口剩下下标数据作比较

### 代码

```swift
class Solution {
    func maxSlidingWindow(_ nums: [Int], _ k: Int) -> [Int] {
        if nums.isEmpty {return []}
        var result: [Int] = []
        var lastMaxValueIndex = -1 //上一次滑动取得最大值的下标
        var lastMaxValueToIndex = -1 //上次滑动取得最大值的比较范围下标
        var maxValue = -Int.max
        
        for i in 0 ..< nums.count - k + 1{
            var starIndex = 0
            if lastMaxValueIndex < i {
                maxValue = -Int.max
            } else {
                starIndex = lastMaxValueToIndex - i
            }
            for j in starIndex ..< k {
                if nums[j + i] > maxValue {
                    maxValue = nums[j + i]
                    lastMaxValueIndex = j + i
                }
            }
            lastMaxValueToIndex = k + i - 1
            result.append(maxValue)
        }
        return result
    }
}

```