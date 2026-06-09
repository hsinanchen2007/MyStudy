``` swift
class Solution {
    func isValid(_ s: String) -> Bool {
        let map: [Character: Character] = [")": "(", "]": "[", "}": "{"]
        var lefts = [Character]()
        for char in s {
            if map.values.contains(char) {
                lefts.append(char)
            } else {
                guard !lefts.isEmpty, map[char] == lefts.removeLast() else { return false }
            }
        }
        return lefts.isEmpty
    }
}
```
