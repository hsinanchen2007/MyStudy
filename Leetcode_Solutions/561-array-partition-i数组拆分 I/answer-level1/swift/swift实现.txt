```
class Solution {
    func arrayPairSum(_ nums: [Int]) -> Int {
        let newNums = nums.sorted()
        var sum = 0
        for (i,v) in newNums.enumerated(){
            if i%2 == 0 {
                sum += v
            }
        }
        return sum
    }
}
```