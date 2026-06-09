```
class Solution {
    func reverseWords(_ s: String) -> String {
        if s == "" { return s }
        var result = ""
        var arr = s.split(separator: " ")
        arr.forEach {
            result += String($0.reversed())
            result += " "
        }
        result.removeLast()
        return result
    }
}
```