class Solution {
    func findMaxConsecutiveOnes(_ nums: [Int]) -> Int {
        
        var maxCount = 0
        var currentMax = 0
        for item in nums {
            if item == 1 {
                currentMax += 1
            }else {
                if currentMax > maxCount {
                    maxCount = currentMax

                }else {
                }
                currentMax = 0
            }
        }
        
        if currentMax > maxCount {
            maxCount = currentMax
            
        }
        
        
        return maxCount
    }
}