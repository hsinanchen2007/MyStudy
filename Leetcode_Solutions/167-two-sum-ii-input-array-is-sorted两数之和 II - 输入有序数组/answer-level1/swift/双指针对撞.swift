class Solution {
    func twoSum(_ numbers: [Int], _ target: Int) -> [Int] {
        
       var low = 0, high = numbers.count - 1
       
        while low < high {
            if numbers[low] + numbers[high] == target {
                return [low + 1, high + 1]
            } else if numbers[low] + numbers[high] > target {
                high -= 1
            } else {
                low += 1
            }
        }
        return [-1, -1]
    }
}