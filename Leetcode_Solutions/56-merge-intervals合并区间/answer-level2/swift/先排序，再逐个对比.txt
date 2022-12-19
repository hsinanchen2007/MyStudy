

class Solution {
    func merge(_ intervals: [[Int]]) -> [[Int]] {
        guard intervals.count > 1 else { return intervals }
        let sortedIntervals = intervals.sorted { $0.first! < $1.first! }
        
        var newIntervals = [[Int]]()
        var newIntervalsLeftElement = sortedIntervals.first?.first
        var newIntervalsRightElement = sortedIntervals.first?.last
        
        for element in sortedIntervals[1...] {
            if newIntervalsRightElement! >= element.first! {
                if newIntervalsRightElement! < element.last! {
                    newIntervalsRightElement = element.last
                }
            } else {
                newIntervals.append([newIntervalsLeftElement!, newIntervalsRightElement!])
                newIntervalsLeftElement = element.first
                newIntervalsRightElement = element.last
            }
        }

        newIntervals.append([newIntervalsLeftElement!, newIntervalsRightElement!])

        return newIntervals
    }
}
```