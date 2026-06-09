### 解题思路


### 代码

```swift
class Solution {
    func compressString(_ S: String) -> String {
        if S.count == 0 {
            return ""
        }
        var result: String = ""
        var times: Int = 0
        var lastStr: Character = S.first!
        for item in S {
            if lastStr == item {
                times += 1
            } else {
                result.append("\(lastStr)\(times)")
                lastStr = item
                times = 1
            }
        }
        result.append("\(lastStr)\(times)")
        return result.count >= S.count ? S:result
    }
}
```