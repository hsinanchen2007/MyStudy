```
func hIndex(_ citations: [Int]) -> Int {
    let length = citations.count
    var left = 0
    var right = length - 1
    while left <= right {
        let mid = (left + right) / 2
        let midCount = citations[mid]
        let remains = length - mid
        if midCount < remains {
            left = mid + 1
        }else if midCount > remains {
            right = mid - 1
        }else{
            return remains
        }
    }
    return length - left
}
```