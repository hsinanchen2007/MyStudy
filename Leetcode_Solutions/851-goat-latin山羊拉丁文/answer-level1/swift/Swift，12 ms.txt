```swift
class Solution {
    func toGoatLatin(_ S: String) -> String {
        let yuan = [Character]("aeiouAEIOU")
        var Ss = S.split(separator: Character(" "))
        for index in 0..<Ss.count {
            var current = Ss[index]
            let first = current.first!
            if !yuan.contains(first) {
                current.removeFirst()
                current += String(first)
            }
            current += ("ma" + String(repeating: "a", count: index + 1))
            Ss[index] = current
        }
        return Ss.joined(separator: " ")
    }
}
```