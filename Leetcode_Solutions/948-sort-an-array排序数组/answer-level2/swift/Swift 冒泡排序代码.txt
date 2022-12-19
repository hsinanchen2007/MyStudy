```
class Solution {
    func sortArray(_ nums: [Int]) -> [Int] {
        var hasChange = true
        var tempNums = nums
        while hasChange {
            print("循环处理排序")
            hasChange = false
            var startIndex = 0
            for (index, value) in tempNums.enumerated() {
                if startIndex == tempNums.count-1 {
                    break
                }
                if tempNums[startIndex] > tempNums[startIndex + 1] {
                    tempNums.swapAt(startIndex, startIndex + 1)
                    hasChange = true
                }
                startIndex += 1
            }
        }
        return tempNums
    }
}
```
