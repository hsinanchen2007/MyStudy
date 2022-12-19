```swift
class Solution {
    func addBinary(_ a: String, _ b: String) -> String {
        let cA = a.count
        let cB = b.count
        var right = [Character](cA > cB ? a.reversed() : b.reversed())
        let left = [Character](cA > cB ? b.reversed() : a.reversed())
        var last: Int = 0
        let cLeft = min(cA, cB)
        let cRight = max(cA, cB)
        for index in 0..<cLeft {
            let newVal = Int(String(left[index]))! + Int(String(right[index]))! + last
            last = 0
            switch newVal {
            case 3, 2:
                right[index] = Character("\(newVal - 2)")
                last = 1
            default:
                right[index] = Character("\(newVal)")
            }
        }
        for index in cLeft..<cRight {
            if last == 0 {
                break
            }
            let newVal = Int(String(right[index]))! + last
            last = 0
            switch newVal {
            case 2:
                right[index] = Character("0")
                last = 1
            default:
                right[index] = Character("\(newVal)")
            }
        }
        if last != 0 {
            right.append("1")
        }
        return String(right.reversed())
    }
}
```