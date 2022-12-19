```swift
class Solution {
    func sumZero(_ n: Int) -> [Int] {
        var ans: [Int] = n % 2 == 1 ? [0] : []
        for index in 1..<(n / 2 + 1) {
            ans.append(contentsOf: [index, -index])
        }
        return ans
    }
}
```