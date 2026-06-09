```
class Solution {
    
    class Stack {
        private var arr = [Character]()
        var top: Character? {
            get {
                return arr.last
            }
        }
        func push(_ c: Character) {
            arr.append(c)
        }
        func pop() {
            arr.removeLast()
        }
    }
    
    func isValid(_ s: String) -> Bool {
        guard s.count % 2 == 0 else {
            return false
        }
        let dic: [Character: Character] = ["[": "]", "(": ")", "{": "}", "!": "!"]
        let badArr: [Character] = [")", "}", "]"]
        let arr = Array(s)
        let stack = Stack()
        for c in arr {
            if c == dic[stack.top ?? "!"] {
                stack.pop()
            } else {
                if badArr.contains(c) {
                    return false
                }
                stack.push(c)
            }
        }
        return stack.top == nil
    }
}
```