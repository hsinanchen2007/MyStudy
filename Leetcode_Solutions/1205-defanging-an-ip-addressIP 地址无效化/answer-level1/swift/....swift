### 解题思路
此处撰写解题思路

### 代码

```swift
class Solution {
    func defangIPaddr(_ address: String) -> String {
        var s = ""
        for c in address {
            s += (c == Character(".") ? "[.]" : String.init(c));
        }
        return s;
    }
}

```