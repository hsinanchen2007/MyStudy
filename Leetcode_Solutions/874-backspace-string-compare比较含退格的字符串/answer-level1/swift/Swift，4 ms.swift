```swift
class Solution {
    func backspaceCompare(_ S: String, _ T: String) -> Bool {
        var newS = [Character](), newT = [Character]()
        for char in S {
            if char == Character("#") {
                if !newS.isEmpty {
                    newS.removeLast()
                }
                continue
            }
            newS.append(char)
        }
        for char in T {
            if char == Character("#") {
                if !newT.isEmpty {
                    newT.removeLast()
                }
                continue
            }
            newT.append(char)
        }
        return newS == newT
    }
}
```