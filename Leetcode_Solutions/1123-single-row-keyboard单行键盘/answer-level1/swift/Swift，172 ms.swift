```swift
class Solution {
    func calculateTime(_ keyboard: String, _ word: String) -> Int {
        let keyboardChars = [Character](keyboard)
        var now = 0, ans = 0
        for char in word {
            let current = keyboardChars.firstIndex(of: char)!
            ans += abs(current - now)
            now = current
        }
        return ans
    }
}
```