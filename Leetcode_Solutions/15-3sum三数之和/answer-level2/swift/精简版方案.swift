### 解题思路
顺序的数组中固定一个数字，然后在固定数字右边的数组中从最左和最右向中间遍历，找到和为零的方案。
思路很简单，具体看一下代码。建议先按解题思路自行解决，回过头来再看代码会记忆深刻。

### 代码

```swift
class Solution {
    func threeSum(_ nums: [Int]) -> [[Int]] {
        // 异常情况
        if nums.count < 3 { return [] }
        
        let sortedNums = nums.sorted()
        
        var result = Set<[Int]>()
        // 顺序的数组中固定一个数字，然后在固定数字右边的数组中从最左和最右向中间遍历，找到和为零的方案。
        for (index, number_first) in sortedNums.enumerated() {
            
            var l = index + 1, r = sortedNums.count - 1
            // 第一个数字大于零后续也会大于零
            if number_first > 0 { break }
            
            while l < r {
                
                let sum = number_first + sortedNums[l] + sortedNums[r]
                if sum == 0 {
                    result.insert([number_first, sortedNums[l], sortedNums[r]])
                    // 找到满足条件的数字,然后还需要继续寻找其他和为零可能的方案，所以需要继续向中间寻找
                    l += 1
                    r -= 1
                }else if sum > 0 {
                    // 类似二分法，和大于零，最右面往左移
                    r -= 1
                }else if sum < 0 {
                    // 类似二分法，和小于零，最左面往右移
                    l += 1
                }
            }
            
        }
        return result.map { $0 }
    }
}
```