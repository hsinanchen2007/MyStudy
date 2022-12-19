```swift
class Solution {
    func repeatedNTimes(_ A: [Int]) -> Int {
        var set = Set<Int>()
        for item in A {
            if set.contains(item) {
                return item
            }
            set.insert(item)
        }
        return A[0]
    }
}
```