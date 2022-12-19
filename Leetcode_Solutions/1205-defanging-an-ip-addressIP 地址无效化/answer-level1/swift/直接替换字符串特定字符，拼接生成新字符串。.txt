### 解题思路
此处撰写解题思路

很简单，首先遍历出给定的 IP 地址字符串中每一个字符，直接替换 "." 字符！

### 代码

```swift
class Solution {
    func defangIPaddr(_ address: String) -> String {
        var myNewIP = ""
        for index in 0..<address.count {
            let ip: Character = address[address.index(address.startIndex, offsetBy: index)]
            var tempStr = ""
            
            if ip == "." {
                tempStr = "[.]"
                myNewIP.append(tempStr)
            }else {
                myNewIP.append(ip)
            }
        }
        return myNewIP
    }
}
```