### 解题思路

1、遍历相加
2、匹配6种特殊情况，减去多加的值

### 代码

```swift
class Solution {
    func romanToInt(_ s: String) -> Int {
        let map:[String: Int] = [
        "I" : 1,
        "V" : 5,
        "X" : 10,
        "L" : 50,
        "C" : 100,
        "D" : 500,
        "M" : 1000
    ]
    var res = 0
    for i in s {
        let v = map[String(i)]
        res += v!
    }
    ///6种情况，需要减去多加的值
    
    matches(for: "IV", in: s).forEach {_ in
        res -= 2
    }
    matches(for: "IX", in: s).forEach {_ in
        res -= 2
    }
    matches(for: "XL", in: s).forEach {_ in
        res -= 20
    }
    matches(for: "XC", in: s).forEach {_ in
        res -= 20
    }
    matches(for: "CD", in: s).forEach {_ in
        res -= 200
    }
    matches(for: "CM", in: s).forEach {_ in
        res -= 200
    }

    return res
    }

    func matches(for regex: String, in text: String) -> [String] {
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

}
```