```swift
class Solution {
    func minTimeToVisitAllPoints(_ points: [[Int]]) -> Int {
        var ans: Int = 0
        for index in 1..<points.count {
            let pointPrevious = points[index - 1]
            let pointCurrent = points[index]
            ans += max(abs(pointCurrent[0] - pointPrevious[0]), abs(pointCurrent[1] - pointPrevious[1]))
        }
        return ans
    }
}
```