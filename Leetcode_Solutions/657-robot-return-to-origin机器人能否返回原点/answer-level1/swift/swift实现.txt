```
class Solution {
    func judgeCircle(_ moves: String) -> Bool {
        var v = 0
        var h = 0
        moves.map {
            switch $0 {
            case "U":
                v += 1
            case "D":
                v -= 1
            case "L":
                h += 1
            case "R":
                h -= 1
            default: break
            }
        }
        return v==0 && h==0
    }
}
```