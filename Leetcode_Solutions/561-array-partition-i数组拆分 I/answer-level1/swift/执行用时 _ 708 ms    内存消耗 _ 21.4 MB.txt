### 解题思路
排序，然后把下标为偶数的相加
### 代码

```swift
class Solution {
    func arrayPairSum(_ nums: [Int]) -> Int {
        var arr = nums;
        arr.sort()
        var sum = 0
        for index in 0..<arr.count/2 {
            let currentIndex = index*2
            sum += arr[currentIndex]
        }
        return sum
    }
}
```