```swift
class Solution {
    func selfDividingNumbers(_ left: Int, _ right: Int) -> [Int] {
        var ans = [Int]()
        for val in left...right {
            var item = val
            var mark = true
            while item != 0 {
                let temp = item % 10
                if temp == 0 || val % temp != 0 {
                    mark = false
                    break
                }
                item /= 10
            }
            if mark {
                ans.append(val)
            }
        }
        return ans
    }
}
```