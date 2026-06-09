解题思路：同三数之和为0类似，通过两个指针来遍历，设定一个初始值，其中最接近通过绝对值来比较

    class Solution {
    func threeSumClosest(_ nums: [Int], _ target: Int) -> Int {
           
        guard nums.count > 2 else {
            return -1
        }
                
        var ans = nums[0] + nums[1] + nums[2]
        
        let sortedNums = nums.sorted()
        
        for i in 0..<sortedNums.count - 1 {
            
            var low = i + 1
            var high = sortedNums.count - 1
            
            while low < high {
                
                let sum = sortedNums[i] + sortedNums[low] + sortedNums[high]
                
                if abs(target - sum)  < abs(target - ans){
                    ans = sum
                }
                
                if sum > target {
                    high = high - 1
                } else if sum < target {
                    low = low + 1
                } else {
                    return ans
                }
            }
        }
        return ans
    }
    }