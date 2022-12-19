执行时间`56ms`，有时间再优化一下
```
class Solution {
    func maxDepthAfterSplit(_ seq: String) -> [Int] {
        let c: [Character] = ["(",")"]
        let vc: [Character] = [")","("]
        var stackA = [Character]()
        var stackB = [Character]()
        var res = [Int]()
        for i in seq {
            let lastA = stackA.last
            let lastB = stackB.last 
            if lastA != nil && ([lastA!,i] == c || [lastA!, i] == vc) {
                stackA.removeLast()
                res.append(0)
            }else if lastB != nil && ([lastB!, i] == c || [lastB!, i] == vc) {
                stackB.removeLast()
                res.append(1)
            }else {
                if stackA.count < stackB.count {
                    stackA.append(i)
                    res.append(0)
                }else{
                    stackB.append(i)
                    res.append(1)
                }
            }
            
        }
        return res
    }
}
```