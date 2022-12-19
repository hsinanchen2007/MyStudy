```
class Solution {
    func countDigitOne(_ n: Int) -> Int {
        return helper(n)
    }
    
    func helper(_ n: Int) -> Int {
        if n <= 0 {
            return 0
        }
        let characters = String(n).map{$0}
        let high = Int(String(characters.first!))!
        let pows = Int(pow(Double(10.0),Double(characters.count - 1)))
        let last = n - pows * high
        if high == 1 {
            return (helper(pows - 1) + last + 1 + helper(last))
        } else {
            return (high * helper(pows - 1) + pows + helper(last))
        }
    }
}
```
//真心吐槽，swift关于字符串和字符数组的语法，还有类型转换真心裹脚布，用着真心难受。