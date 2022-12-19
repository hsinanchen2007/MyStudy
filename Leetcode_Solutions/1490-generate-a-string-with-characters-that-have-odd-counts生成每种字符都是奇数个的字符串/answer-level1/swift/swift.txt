### 解题思路
此处撰写解题思路

### 代码

```swift
class Solution {
    func generateTheString(_ n: Int) -> String {
        var result = ""
        if n%2 == 0 {
            result.append("x")
            for _ in 1...n-1 {
                result.append("y")
            }
        } else {
            for _ in 1...n {
                result.append("x")
            }
        }
        return result
    }
}
```