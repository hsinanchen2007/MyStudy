### 解题思路
1. 使用栈保存每一轮的得分
2. 遍历的时候累加得到最终结果

### 代码

```swift
class Solution {
    func calPoints(_ ops: [String]) -> Int {
        var roundPoint = [Int]()
        var sum = 0 
        for char in Array(ops) {
            let point: Int
            if char == "C" {
                let popped = roundPoint.popLast()
                point = -(popped ?? 0)
            } else if char == "D" {
                point = (roundPoint.last ?? 0) * 2
                roundPoint.append(point)
            } else if char == "+" {
                let pop1 = roundPoint.popLast() ?? 0
                let pop2 = roundPoint.popLast() ?? 0
                point = pop1 + pop2
                roundPoint.append(pop2)
                roundPoint.append(pop1)
                roundPoint.append(point)
            } else {
                point = Int(char) ?? 0
                roundPoint.append(point)
            }
            sum += point
        }
        return sum
    }
}

```