```
func removeElement(_ nums: inout [Int], _ val: Int) -> Int {
        for item in nums {
            if let index = nums.firstIndex(of: item) {
                if item == val {
                    nums.remove(at: index)
                }
            }
        }
        return nums.count
    }
```