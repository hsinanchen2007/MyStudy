```swift
class NumArray {

    var dp: [Int?]
    let nums: [Int]
    
    init(_ nums: [Int]) {
        self.nums = nums
        let numsCount = nums.count
        dp = [Int?](repeating: nil, count: numsCount + 1)
        dp[0] = 0
    }
    
    func sumRange(_ i: Int, _ j: Int) -> Int {
        return sum(j + 1) - sum(i)
    }
    
    func sum(_ i: Int) -> Int {
        if let val = dp[i] {
            return val
        }
        let newDp = sum(i - 1) + nums[i - 1]
        dp[i] = newDp
        return newDp
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * let obj = NumArray(nums)
 * let ret_1: Int = obj.sumRange(i, j)
 */
```