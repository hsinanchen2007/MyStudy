```
class Solution {
    func nextGreatestLetter(_ letters: [Character], _ target: Character) -> Character {
        var i = 0
        let vt = Int(target.asciiValue!)
        while i < letters.count {
            let vi = Int(letters[i].asciiValue!)
            if vi > vt {
                return letters[i]
            }
            i += 1
        }
        return letters[0]
    }
}
```