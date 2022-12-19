```
class Solution {
    func calPoints(_ ops: [String]) -> Int {
        var scoreStack:[Int] = []
        var score = 0
        for item in ops {
            switch item {
            case "+":
                score = scoreStack.last! + scoreStack[scoreStack.count-2]
                scoreStack.append(score)
            case "D":
                score = scoreStack.last!*2
                scoreStack.append(score)
            case "C":
                score = scoreStack.popLast()!
            default:
                scoreStack.append(Int(item)!)
            }
        }
        return scoreStack.reduce(0,+)
    }
}
```
