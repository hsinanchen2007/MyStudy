```swift
class Solution {
    func removeVowels(_ S: String) -> String {
        var ans = String(S)
        ans.removeAll { (char) -> Bool in
            return Character("a") == char
                || Character("e") == char
                || Character("i") == char
                || Character("o") == char
                || Character("u") == char
        }
        return ans
    }
}
```