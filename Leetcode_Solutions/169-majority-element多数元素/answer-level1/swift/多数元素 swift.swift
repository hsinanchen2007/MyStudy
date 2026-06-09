### 解题思路
遍历+记忆

### 代码

```swift
class Solution {
    func majorityElement(_ nums: [Int]) -> Int {
        var memo = [Int]() // 记录已经遍历过的数
        var maxCount = 0 // 记录最大出现次数
        var maxNum = nums[0] // 记录出现最多次的数
        for i in 0..<nums.count {
            if !memo.contains(nums[i]) {
                memo.append(nums[i])
                let num = nums[i]
                var maxCountTemp = 0 // 用于计算当前数字出现次数的临时变量
                for j in i..<nums.count {
                    if (num == nums[j]) {
                        maxCountTemp += 1
                    }
                }
                if maxCountTemp > maxCount { // 如果当前数字出现的次数大于记录出现最多次数，则更新记录
                    maxNum = num
                    maxCount = maxCountTemp
                }
            }
        }
        return maxNum
    }
}
```