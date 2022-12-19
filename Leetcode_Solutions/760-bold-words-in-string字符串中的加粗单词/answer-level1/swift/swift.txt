### 解题思路
此处撰写解题思路

### 代码

```swift
class Solution {
    func boldWords(_ words: [String], _ S: String) -> String {
            let n =  S.count
            var signArray = Array(repeating: false, count: n)
            let ns_S = S as NSString
            for word in words {
                var left = 0
                while left < n {
                    let range = ns_S.range(of: word, range: NSRange(location: left, length: n - left))
                    if range.length == 0 {
                        break
                    }else {
                        let idx = range.lowerBound
                        for i in idx ..< idx + word.count {
                            signArray[i] = true;
                        }
                        left += 1;
                    }
                }
            }
            var new_S = ""
            var i = 0
            while i < n {
                while i < n && signArray[i] == false {
                    new_S += ns_S.substring(with: NSRange(location: i, length: 1))
                    i += 1
                }
                if i == n {
                    break
                }
                new_S += "<b>"
                while i < n && signArray[i] == true {
                    new_S += ns_S.substring(with: NSRange(location: i, length: 1))
                    i += 1
                }
                new_S += "</b>"
            }
            print(signArray)
            return new_S as String
        }
}
```