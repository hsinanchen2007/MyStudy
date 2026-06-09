```
func searchInsert(_ nums: [Int], _ target: Int) -> Int {
        if let index = nums.firstIndex(of: target) {
            return index
        }
        var array = nums
        array.append(target)
        array.sort()
        return array.firstIndex(of: target)!
    }
```