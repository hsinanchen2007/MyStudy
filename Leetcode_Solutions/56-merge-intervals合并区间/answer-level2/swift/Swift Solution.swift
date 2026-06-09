```
func merge(_ intervals: [[Int]]) -> [[Int]] {
    
    if intervals.count == 0 {
        return [[Int]]()
    }
    
    let sorted = intervals.sorted { (itval1, itval2) -> Bool in
        if itval1[0] != itval2[0] {
            return itval1[0] < itval2[0]
        } else {
            return itval1[1] < itval2[1]
        }
    }
    
    var merged = [[Int]]()
    
    var currentInterval = sorted[0]
    
    for i in 1..<sorted.count {
        let interval = sorted[i]
        
        if currentInterval[1] >= interval[0] {
            currentInterval = [currentInterval[0], max(currentInterval[1], interval[1])]
        } else {
            merged.append(currentInterval)
            currentInterval = interval
        }
    }
    
    merged.append(currentInterval)
    
    return merged
}
```
