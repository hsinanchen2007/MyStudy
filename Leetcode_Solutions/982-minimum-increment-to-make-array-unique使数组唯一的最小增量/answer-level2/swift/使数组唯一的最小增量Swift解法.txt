### 解题思路

### 代码

```swift
class Solution {
    func minIncrementForUnique(_ A: [Int]) -> Int {
        if A.isEmpty {
            return 0
        }
        var sortedArr = A.sorted(by: <)
        var res = 0
        for i in 1..<sortedArr.count {
            let pre = sortedArr[i - 1]
            let cur = sortedArr[i]
            if pre>=cur {
                res += pre - cur + 1
                sortedArr[i] = pre + 1
            }
        }
        return res
    }
}
```