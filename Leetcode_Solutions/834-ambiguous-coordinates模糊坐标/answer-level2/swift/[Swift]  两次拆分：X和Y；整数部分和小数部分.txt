```swift
class Solution {
    func ambiguousCoordinates(_ S: String) -> [String] {
        var ans: Set<String> = []
        var y = S
        y.removeFirst()
        y.removeLast()
        var x  = ""
        while y.count > 1 {
            x.append(y.removeFirst())
            let xs = decodePotentialNumbersFrom(numberString: x)
            let ys = decodePotentialNumbersFrom(numberString: y)
            for currentX in xs {
                for currentY in ys {
                    ans.insert("(\(currentX), \(currentY))")
                }
            }
        }
        return Array<String>(ans)
    }
    private func decodePotentialNumbersFrom(numberString str: String) -> [String] {
        guard str.count > 1 else {
            return [str]
        }
        guard !str.filter({$0 != "0"}).isEmpty else {
            return []
        }
        var ans = [String]()
        if !str.hasPrefix("0") {
            ans.append(str)
        }
        var decimal = str
        var integer = ""
        while decimal.count > 1 {
            integer.append(decimal.removeFirst())
            if integer.count == 1 || !integer.hasPrefix("0") {
                if !decimal.hasSuffix("0") {
                    ans.append(integer + "." + decimal)
                }
            }
        }
        return ans
    }
}

```
