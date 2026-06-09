```
func evalRPN(_ tokens: [String]) -> Int {
        var stack: Array<Int> = []
        for string in tokens {
            if "+-*/".contains(string) {
                let left = stack.last!
                stack.removeLast()
                let right = stack.last!
                stack.removeLast()
                var temp = 0
                switch string {
                case "+": temp = right + left
                case "-": temp = right - left
                case "*": temp = right * left
                case "/": temp = right / left
                default: break
                }
                stack.append(temp)
            }
            else {
                stack.append(Int(string)!)
            }
        }
        return stack.first!
    }
```