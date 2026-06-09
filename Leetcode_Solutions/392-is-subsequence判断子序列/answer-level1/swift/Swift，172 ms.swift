```swift
class Solution {
    func isSubsequence(_ s: String, _ t: String) -> Bool {
        if s.isEmpty {
            return true
        }
        if s.count == 1 {
            return t.contains(s.first!)
        }
        if t.isEmpty {
            return false
        }
        var leftS = s.index(s.startIndex, offsetBy: 0), rightS = s.index(s.endIndex, offsetBy: -1)
        var leftT = t.index(t.startIndex, offsetBy: 0), rightT = t.index(t.endIndex, offsetBy: -1)
        while leftS < rightS {
            guard let tryLeftT = t[leftT...rightT].firstIndex(of: s[leftS]) else { return false }
            if tryLeftT > rightT { return false }
            leftT = t.index(tryLeftT, offsetBy: 1)
            leftS = s.index(leftS, offsetBy: 1)
            guard let tryRightT = t[leftT...rightT].lastIndex(of: s[rightS]) else { return false }
            if tryRightT < leftT { return false }
            rightT = t.index(tryRightT, offsetBy: -1)
            rightS = s.index(rightS, offsetBy: -1)
            if leftS == rightS {
                if leftT == rightT {
                    return t[rightT] == s[leftS]
                }
                return t[leftT..<rightT].contains(s[leftS])
            }
        }
        return true
    }
}
```