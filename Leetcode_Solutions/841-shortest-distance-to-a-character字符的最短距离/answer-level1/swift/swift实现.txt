```
func shortestToChar(_ S: String, _ C: Character) -> [Int] {
    var indexList:[Int] = []
    var result = [Int]()
    for (index,value) in S.enumerated() {
        if value == C {
            indexList.append(index)
        }
    }
    for (index,_) in S.enumerated() {
        result.append(indexList.map { abs($0-index) }.min()!)
    }
    return result
}
```
