```
class Solution {
    func numJewelsInStones(_ J: String, _ S: String) -> Int {
        if J.count == 0 ||  S.count == 0 {
            return 0
        }
        var jSet = Set<Character>()
        var count = 0
        for ch in J {
            jSet.insert(ch)
        }
        for s in S {
            if jSet.contains(s) {
                count += 1
            }
        }
        return count
    }
}
```
