### 解题思路
enumerated 简直是性能杀手
### 代码

```swift
class Solution {
 func compressString(_ S: String) -> String {
    if S.isEmpty {
        return ""
    }
    
    var str = ""
    
    var count = 0
    var temp = S.first!
    
    for item in S {
        if temp == item {
            count += 1
        } else {
            str.append("\(temp)\(count)")
            count = 1
            temp = item
        }
    }
    str.append("\(temp)\(count)")
    if S.count <= str.count {
        return S
    }
    return str
 }
 
 
}
```