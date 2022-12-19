### 解题思路
此处撰写解题思路

### 代码

```swift
class Solution {
    func topKFrequent(_ nums: [Int], _ k: Int) -> [Int] {
        var dic: [Int: Int] = [:]
    for i in 0..<nums.count {
        var value = 0
        if dic[nums[i]] != nil {
            value = dic[nums[i]]!
        }
        value += 1
        dic.updateValue(value, forKey: nums[i])
    }

    let stored = dic.sorted { $0.value > $1.value }
    return stored[0..<k].map { $0.key }
    }
}
```