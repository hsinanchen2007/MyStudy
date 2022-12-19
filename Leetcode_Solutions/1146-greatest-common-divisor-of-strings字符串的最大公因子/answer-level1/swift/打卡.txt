### 解题思路
利用最大公约数来完成

### 代码

```swift
class Solution {
    func gcdOfStrings(_ str1: String, _ str2: String) -> String {
        if (str1 + str2 == str2 + str1) {
            var a = str1.count
            var b = str2.count
            while a % b != 0 {
                let temp = a % b
                a = b
                b = temp
            }
            return String(str1.prefix(b))
        } else {
            return ""
        }
    }
}
```