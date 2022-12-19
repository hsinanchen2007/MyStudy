```
func lengthOfLastWord(_ s: String) -> Int {
        let str = s.trimmingCharacters(in: .whitespaces)
        if str.count == 0 {
            return 0
        }
        let array = str.components(separatedBy: " ")
        return array.last!.count
    }
```