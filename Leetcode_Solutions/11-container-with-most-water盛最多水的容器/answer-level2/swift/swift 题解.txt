```
class Solution {
    func maxArea(_ height: [Int]) -> Int {
        var i = 0
        var j = height.count - 1
        var res = 0
        while i<j {
            if height[i] < height[j] {
                res = max(res, height[i] * (j - i))
                i += 1
            } else {
                res = max(res, height[j] * (j - i))
                j -= 1
            }
        }
        return res
    }
}
```
