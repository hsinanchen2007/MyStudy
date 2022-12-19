```swift
class Solution {
    func numberOfBoomerangs(_ points: [[Int]]) -> Int {
        let pointsCount = points.count
        var memo: [[Int]] = [[Int]](repeating: [Int](repeating: 0, count: pointsCount), count: pointsCount)
        var ans = 0
        for i in 0..<pointsCount {
            let first = points[i]
            for j in (i + 1)..<pointsCount {
                let second = points[j]
                let disX = abs(second[0] - first[0])
                let disY = abs(second[1] - first[1])
                let dis = disX * disX + disY * disY
                memo[i][j] = dis
                memo[j][i] = dis
            }
        }
        for i in 0..<pointsCount {
            var dict: [Int: Int] = [:]
            for item in memo[i] {
                if dict.keys.contains(item) {
                    dict[item]! += 1
                } else {
                    dict.updateValue(1, forKey: item)
                }
            }
            for item in dict {
                if item.value > 1 {
                    ans += (item.value * (item.value - 1))
                }
            }
        }
        return ans
    }
}
```