```swift
class Solution {
    func twoCitySchedCost(_ costs: [[Int]]) -> Int {
        let costsCountHalf = costs.count / 2
        let costsSorted = costs.sorted(by: { return abs($0[0] - $0[1]) > abs($1[0] - $1[1]) })
        var ans = 0
        var count0 = 0
        var count1 = 0
        for cost in costsSorted {
            var choose0 = true
            if count0 >= costsCountHalf {
                choose0 = false
            } else if count1 < costsCountHalf {
                if cost[0] > cost[1] {
                    choose0 = false
                }
            }
            if choose0 {
                count0 += 1
                ans += cost[0]
            } else {
                count1 += 1
                ans += cost[1]
            }
        }
        return ans
    }
}
```