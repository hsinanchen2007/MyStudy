```swift
class Solution {
    func merge(_ intervals: [[Int]]) -> [[Int]] {
        if intervals.count <= 1 { return intervals }
        let intervalsSorted = intervals.sorted(by: { $0[0] < $1[0] })
        var ans = [[Int]]()
        var last = intervalsSorted[0]
        for item in intervalsSorted {
            if last[1] >= item[0] {
                last[1] = max(last[1], item[1])
            } else {
                ans.append(last)
                last = item
            }
        }
        ans.append(last)
        return ans
    }
}
```