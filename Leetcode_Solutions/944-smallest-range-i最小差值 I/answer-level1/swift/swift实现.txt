 用最大数减去k的最大值减去最小数加上k的最大值即可。
```
class Solution {
    func smallestRangeI(_ A: [Int], _ K: Int) -> Int {
        let min = A.min() ?? 0
        let max = A.max() ?? 0
        if (max-K)<(min+K) {
            return 0
        }
        return max-min-2*K
    }
}
```