```
class Solution {
    func maxArea(_ height: [Int]) -> Int {
        var maxWater = 0
        var slowIndex = 0
        var fastIndex = height.count - 1
        
        while slowIndex < fastIndex {
            let tempWater = (fastIndex - slowIndex) * min(height[slowIndex], height[fastIndex])
            maxWater = max(maxWater, tempWater)
            if height[slowIndex] < height[fastIndex] {
                slowIndex += 1
            } else {        
                fastIndex -= 1
            }
        }
        return maxWater
    }
}
```
