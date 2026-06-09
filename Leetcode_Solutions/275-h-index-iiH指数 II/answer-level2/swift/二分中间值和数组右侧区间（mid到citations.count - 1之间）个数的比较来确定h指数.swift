```
class Solution {
    func hIndex(_ citations: [Int]) -> Int {
        if citations.count == 0 {
            return 0
        }
        var l = 0, r = citations.count - 1, rets = [Int]()
        while l <= r {
            let m = l + (r - l) >> 1
            if citations[m] >= citations.count - m {
                rets.append(citations.count - m)
                r = m - 1
            } else {
                l = m + 1
            }
        }
        return rets.last ?? 0
    }
}
```
