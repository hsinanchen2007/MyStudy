``` swift
class Solution {
    func isValid(_ s: String) -> Bool {
        func isPair(_ a: Character, _ b: Character) -> Bool {
            return (a == "(" && b == ")") || (a == "[" && b == "]") || (a == "{" && b == "}")
        }
        enum Direction {
            case left
            case right
            static func getDirection(_ char: Character) -> Direction {
                switch char {
                case "(", "[", "{":
                    return left
                default:
                    return right
                }
            }
        }
        
        var unpaired: [Character] = []
        for char in s {
            let direction = Direction.getDirection(char)
            switch direction {
            case .left:
                unpaired.append(char)
            case .right:
                if !isPair(unpaired.last ?? " ", char) {
                    return false
                } else {
                    unpaired.removeLast(1)
                }
            }
        }
        return unpaired.isEmpty
    }
}
```