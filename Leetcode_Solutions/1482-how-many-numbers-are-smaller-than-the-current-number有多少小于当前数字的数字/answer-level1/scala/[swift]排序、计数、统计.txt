
```swift
 class Solution {
    func smallerNumbersThanCurrent(_ nums: [Int]) -> [Int] {
        let sortArr = nums.sorted()
        var map = [Int:Int]()
        for i in 0..<nums.count {
            if nil == map[sortArr[i]] {
                map.updateValue(i, forKey: sortArr[i])
            }
        }
        return nums.map {map[$0]!}
    }
 }

```