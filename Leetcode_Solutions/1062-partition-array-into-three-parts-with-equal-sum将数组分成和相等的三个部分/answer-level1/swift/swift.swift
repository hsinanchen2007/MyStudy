### 解题思路
数组划分三个子数组, 三个数组和相等, sum = A.sum/3
A.sum 不能被3整除时就无法满足
遍历, 能找到两个分割点, 验证三部分和都相等
遍历的时候验证了前两部分, 再验证最后一部分
### 代码

```swift
class Solution {
    func canThreePartsEqualSum(_ A: [Int]) -> Bool {
        let sumA = A.reduce(0, +)
        guard sumA%3 == 0 else {
            return false
        }
        
        let sum = sumA/3
        
        var count = 2
        var currentSum = 0
        var secondIndex = 0
        
        for i in 0..<A.endIndex {
            currentSum += A[i]
            if currentSum == sum {
                currentSum = 0
                count -= 1
                
                if count == 0 {
                    secondIndex = i+1
                    break
                }
            }
        }
        guard secondIndex < A.endIndex else {
            return false
        }
        return A[secondIndex...].reduce(0, +) == sum
    }

}
```