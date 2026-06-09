```
class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var map = [Int: Int]()
        for (index, num) in nums.enumerated() {
            if let value = map[target - num] {
                return [value, index]
            }else {
                map[num] = index
            }
        }
        return []
    }
}
```
