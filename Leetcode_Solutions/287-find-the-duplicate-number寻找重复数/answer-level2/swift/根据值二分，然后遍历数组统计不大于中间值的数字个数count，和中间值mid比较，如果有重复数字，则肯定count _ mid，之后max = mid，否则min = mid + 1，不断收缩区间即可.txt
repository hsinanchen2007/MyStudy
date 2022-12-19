```
class Solution {
    func findDuplicate(_ nums: [Int]) -> Int {
        var min = 1, max = nums.count - 1
        while (min < max) {
            let mid = min + (max - min) >> 1
            var count = 0
            for num in nums {
                if num <= mid {
                    count += 1
                }
            }
            if count > mid {
                max = mid
            }else {
                min = mid + 1
            }
        }
        return min
    }
}
```
