### 解题思路

### 代码

```swift
class Solution {
    func backspaceCompare(_ S: String, _ T: String) -> Bool {
        let s1 = getRealString(S)
        let s2 = getRealString(T)
        return s1.count == s2.count && s1 == s2
    }

    func getRealString(_ str: String) -> String {
        var stack = [Character]()
        for c in str {
            if c != "#" {
                stack.append(c)
            } else if !stack.isEmpty {
                stack.removeLast()
            }
        }
        return String(stack)
    }
}
```