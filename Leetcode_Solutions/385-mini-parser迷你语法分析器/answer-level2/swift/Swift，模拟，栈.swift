执行用时 :112 ms
内存消耗 : 22.7 MB

```swift
class Solution {
    func deserialize(_ s: String) -> NestedInteger {
        var integerStr = ""
        var stack = [NestedInteger()]
        var lastInteger = stack.first
        
        func transformInteger() -> NestedInteger? {
            guard let val = Int(integerStr) else {
                return nil
            }
            let integer = NestedInteger()
            integer.setInteger(val)
            integerStr = ""
            return integer
        }
        
        s.forEach { c in
            switch c {
            case "[":
                let integer = NestedInteger()
                lastInteger?.add(integer)
                lastInteger = integer
                stack.append(integer)
            case "]":
                if let integer = transformInteger() {
                    lastInteger?.add(integer)
                }
                stack.removeLast()
            case "-", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9":
                integerStr.append(c)
            case ",":
                lastInteger = stack.last
                guard let integer = transformInteger() else {
                    return
                }
                lastInteger?.add(integer)
            default:
                break
            }
        }
        
        if let integer = transformInteger() {
            lastInteger?.add(integer)
        }
        return stack.first?.getList().first ?? NestedInteger()
    }
}
```