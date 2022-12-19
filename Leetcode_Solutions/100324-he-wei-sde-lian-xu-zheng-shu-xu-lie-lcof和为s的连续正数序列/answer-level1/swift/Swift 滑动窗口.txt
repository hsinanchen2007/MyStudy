```
class Solution {
     func findContinuousSequence(_ target: Int) -> [[Int]] {
        var left = 1
        var right = 1
        var sum = 0
        
        var res = [[Int]]()
        while left <= target / 2 {
            if sum < target {
                sum += right
                right += 1
            } else if sum > target {
                sum -= left
                left += 1
            } else {
                var sumArray = [Int]()
                for i in left..<right {
                    sumArray.append(i)
                }
                res.append(sumArray)
                sum -= left
                left += 1
            }
        }
        return res
    }
}
```