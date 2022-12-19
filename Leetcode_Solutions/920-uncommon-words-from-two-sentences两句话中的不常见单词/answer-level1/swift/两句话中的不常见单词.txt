合并然后切割单词，之后看单词在数组中第一次出现和最后一次出现的下标索引是否相同，相同则出现一次，不同则至少有两次以上。
```swift 
class Solution {
    func uncommonFromSentences(_ A: String, _ B: String) -> [String] {
        var result = [String]()
        let C = A + " " + B
        let strArray = C.components(separatedBy: " ")
        for  str in strArray {
            if strArray.firstIndex(of: str) == strArray.lastIndex(of: str) {
                result.append(str)
            }
        }
        return result;
    }
}
```

