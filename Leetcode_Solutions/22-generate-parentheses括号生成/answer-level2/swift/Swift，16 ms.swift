```swift
class Solution {
    var ans = [String]()
    
    func generateParenthesis(_ n: Int) -> [String] {
        fork(left: n, right: n, current: "")
        return ans
    }
    
    func fork(left: Int, right: Int, current: String) {
        if right > 0 {
            if left > 0 {
                fork(left: left - 1, right: right, current: current + "(")
            }
            if right > left {
                fork(left: left, right: right - 1, current: current + ")")
            }
        } else {
            ans.append(current)
        }
    }
}
```