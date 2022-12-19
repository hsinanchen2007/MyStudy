### 解题思路

这里使用双枚举，解决实际问题中存在不断新增各种括号问题。

### 代码

```swift
class Solution {
    func isValid(_ s: String) -> Bool {
        enum Bracket {
            case round
            case square
            case curly
            case angle
        }

        enum DirectionBracket {
            case left(Bracket)
            case right(Bracket)
            static func getBracket(_ c: Character) -> DirectionBracket? {
                switch c {
                case "(": return left(.round)
                case ")": return right(.round)
                case "[": return left(.square)
                case "]": return right(.square)
                case "{": return left(.curly)
                case "}": return right(.curly)
                case "<": return left(.angle)
                case ">": return right(.angle)
                default: return nil
                }
            }

            func pair(_ bracket: DirectionBracket) -> Bool {
                if case .left(let lbr) = self,
                    case .right(let rbr) = bracket {
                    return lbr == rbr
                }
                if case .right(let lbr) = self,
                    case .left(let rbr) = bracket {
                    return lbr == rbr
                }
                return false
            }
        }

        var unpaired = [Character]()
        for c in s {
            guard let bracket = DirectionBracket.getBracket(c) else {
                return false
            }
            switch bracket {
            case .left(let _):
                unpaired.append(c)
            case .right(let _):
                guard let left = DirectionBracket.getBracket(unpaired.last ?? " ") else {
                    return false
                }
                if !left.pair(bracket) {
                    return false
                }
                unpaired.popLast()
            }
        }
        return unpaired.isEmpty
    }
}
```