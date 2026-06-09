```
class Solution {
    func findRepeatNumber(_ nums: [Int]) -> Int {
        var numsSet:Set<Int> = Set()
        
        for i in nums {
            if numsSet.contains(i) {
                return i
            }else{
                numsSet.insert(i)
            }
        }
        
        return -1
    }
}
```