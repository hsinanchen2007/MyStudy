```
class Solution {
    func minRemoveToMakeValid(_ s: String) -> String {
        let lc: String.Element = "("
        let rc: String.Element = ")"
        var stack: [Character] = []
        var lefts: [Int] = []
        var flip = 0
        for (i,c) in s.enumerated() {
            if c == lc {
                lefts.append(i)
            }else if c == rc {
                if lefts.last != nil {
                    stack.insert(lc, at: lefts.last! - (lefts.count - 1) - flip)
                    stack.append(c)
                    lefts.removeLast()
                }else{
                    flip += 1
                }
            }else{
                stack.append(c)
            }
        }
        return String(stack)
    }
}
```