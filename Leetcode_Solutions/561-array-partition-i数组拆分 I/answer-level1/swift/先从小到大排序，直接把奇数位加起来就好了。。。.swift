```
func arrayPairSum(_ nums: [Int]) -> Int {
    var mutNums = nums
    mutNums.sort { (a, b) -> Bool in
        return a < b
    }
    var sum = 0
    for (index, _) in mutNums.enumerated() {
        if (index + 1) % 2 == 0 {
            continue
        }
        sum += mutNums[index]
    }
    return sum
}
```
