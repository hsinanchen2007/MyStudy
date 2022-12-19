### 解法一：暴力解法
```
private var nums: [Int] = []
init(_ nums: [Int]) {
    self.nums = nums
}
    
func sumRange(_ i: Int, _ j: Int) -> Int {
    var sum = 0
    for index in i...j {
        sum += nums[index]
    }
    return sum
 }
```

### 解法二：动态规划

```swift
class NumArray {


    private var sums: [Int] = []
    init(_ nums: [Int]) {
        if nums.count == 0 {
            return
        }
        // sums[i]: sum[0] + sum[1] + .... + sum[i]
        // sum[i] = sum[i - 1] + nums[i] i>= 1
        sums = [Int](repeating: 0, count: nums.count)
        sums[0] = nums[0]
        for i in 1..<nums.count {
            sums[i] = sums[i - 1] + nums[i]
        }
    }
    
    func sumRange(_ i: Int, _ j: Int) -> Int {
        if i == 0 {
            return sums[j]
        }
        return sums[j] - sums[i - 1]
    }

}

/**
 * Your NumArray object will be instantiated and called as such:
 * let obj = NumArray(nums)
 * let ret_1: Int = obj.sumRange(i, j)
 */
```