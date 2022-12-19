```
 class Solution {
     func findRepeatNumber(_ nums: [Int]) -> Int {
        if nums.count == 0 {
            return -1
        }
        var set = Set<Int>()
        for num in nums {
            if set.contains(num) {
                return num
            } else {
                set.insert(num)
            }
        }
        return -1
     }
 }
```