```
func searchRange(_ nums: [Int], _ target: Int) -> [Int] {
        if !nums.contains(target) {
            return [-1, -1]
        }
        let startIndex = nums.firstIndex(where: {$0 == target})!
        let endIndex = nums.lastIndex(where: {$0 == target})!
        return [startIndex, endIndex]
    }
```