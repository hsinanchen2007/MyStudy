没啥毛病，就是效率可能低了点
1、如果是空字符串，直接满足
2、如果字符串长度不是偶数，直接不满足
```
    func isValid(_ s: String) -> Bool {
        if s == "" {
            return true
        }
        if s.count % 2 != 0 {
            return false
        }
        var temp = s
        while (temp.contains("()") || temp.contains("{}") || temp.contains("[]")) {
            temp = temp.replacingOccurrences(of: "()", with: "")
            temp = temp.replacingOccurrences(of: "{}", with: "")
            temp = temp.replacingOccurrences(of: "[]", with: "")
        }
        return temp.count == 0 ? true : false
    }
```