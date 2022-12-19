### 解题思路
菜鸡分享（顶锅盖逃跑

### 代码

```swift
class Solution {
    func missingNumber(_ nums: [Int]) -> Int {

        let set1 = Set(nums)
        var set2 = Set<Int>()
        for i in 0...nums.count {
            set2.insert(i)
        }
        set2 = set2.subtracting(set1)
        var  result = [Int]()
        for i in set2 {
            result.append(i)
        }
        return result.first!
    }
}
```