暴力的for循环遍历操作，第一回忘了排序
```
func relativeSortArray(_ arr1: [Int], _ arr2: [Int]) -> [Int] {
    var result = Array<Int>()
    for (_, value2) in arr2.enumerated() {
        for (_, value1) in arr1.enumerated() {
            if value2 == value1 {
                result.append(value1)
            }
        }
    }
    var sort = Array<Int>()
    for (_, value1) in arr1.enumerated() {
        if !result.contains(value1) {
            sort.append(value1)
        }
    }
    sort.sort()
    result.append(contentsOf: sort)
    return result
}
```