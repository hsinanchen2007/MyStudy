### 解题思路
此处撰写解题思路

### 代码

```swift
class Solution {
    func myAtoi(_ str: String) -> Int {
        var string = str.trimmingCharacters(in: .whitespaces)
    let firstChar = string.first
    var isNegative = false
    if firstChar == "-" {
        isNegative = true
        string =  String(string.suffix(string.count - 1))
    } else if firstChar == "+" {
        isNegative = false
        string =  String(string.suffix(string.count - 1))
    }
    else if !["0","1","2","3","4","5","6","7","8","9"].contains(firstChar) {
        return 0
    }

    let numCheck = string.first
    if !["0","1","2","3","4","5","6","7","8","9"].contains(numCheck) {
        return 0
    }

    ///判断是不是数字
    let matched = matches(for: "[\\d]+", in: string)
    guard let first = matched.first else {
        return 0
    }
    var num: Int = 0
    if first.count != 0 {
        num = Int(first) ?? 0
        if isNegative {
            num = -num
        }
        let min = Int(poww(radix: -2, power: 31))
        let max = Int(poww(radix: 2, power: 31) - 1)
        if num < min {
            num = min
        } else if num > max {
            num = max
        }  else if Int(first) == nil && isNegative {
            num = min
        } else if Int(first) == nil && isNegative == false {
            num = max
        }
    }
    return num
    }
    public func matches(for regex: String, in text: String) -> [String] {
    do {
        let regex = try NSRegularExpression(pattern: regex)
        let results = regex.matches(in: text,
                                    range: NSRange(text.startIndex..., in: text))
        return results.map {
            String(text[Range($0.range, in: text)!])
        }
    } catch let error {
        print("invalid regex: \(error.localizedDescription)")
        return []
    }
}


func poww (radix: Int, power: Int) -> Int {
    return Int(pow(Double(radix), Double(power)))
}
}
```