### 解题思路

### 代码

```swift
class Solution {
    func minimumLengthEncoding(_ words: [String]) -> Int {
        if words.isEmpty {
            return 0
        }
        var wordSet = Set<String>(words)
        for str in wordSet {
            for i in 1..<str.count {
                wordSet.remove(str.subString(i))
            }
        }
        var res = 0
        for str in wordSet {
            res += str.count + 1
        }
        return res
   
    }
}

extension String {
     // 截取字符串
     // index开始索引
     //  开始到结尾
    func subString(_ index: Int) -> String {
        let start = self.index(self.endIndex, offsetBy: index - self.count)
        return String(self[start..<endIndex])
    } 
}
```