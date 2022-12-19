```
class Solution {
    func arrangeCoins(_ n: Int) -> Int {
        var left = 0, right = n
        while left <= right {
            let mid = left + (right - left) / 2
            let sum = mid * (mid + 1) / 2
            if sum == n {
                return mid
            }else if sum > n {
                right = mid - 1
            }else {
                left = mid + 1
            }
        }
        return right
    }
}
```
执行用时 :16 ms, 在所有 swift 提交中击败了60.00%的用户
内存消耗 :20.4 MB, 在所有 swift 提交中击败了20.00%的用户