### 解题思路
直接调用系统函数即可

### 代码

```swift
class Solution {
    func replaceSpace(_ s: String) -> String {
        return s.replacingOccurrences(of: " ", with: "%20")

    }
}
```