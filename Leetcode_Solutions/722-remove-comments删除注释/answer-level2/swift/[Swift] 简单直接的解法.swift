```swift
class Solution {
    func removeComments(_ source: [String]) -> [String] {
        //合并成一个 字符串
        var sourceCode = ""
        for s in source {
            sourceCode += s
            // "#" : 作为原始分行的结尾
            sourceCode += "#"
        }
        var sourceCodeWithoutComments = ""
        while !sourceCode.isEmpty {
            if sourceCode.hasPrefix("//") {
                sourceCode.removeFirst(2)
                while !sourceCode.hasPrefix("#") {
                    sourceCode.removeFirst()
                }
            } else if sourceCode.hasPrefix("/*") {
                sourceCode.removeFirst(2)
                while !sourceCode.hasPrefix("*/") {
                    sourceCode.removeFirst()
                }
                sourceCode.removeFirst(2)
            } else {
                sourceCodeWithoutComments.append(sourceCode.removeFirst())
            }
        }
        //拆分成不同的行
        let lines = sourceCodeWithoutComments.split(separator: "#")
        var ans =  [String]()
        for line in lines {
            if  !line.isEmpty {
                ans.append(String(line))
            }
        }
        return ans
    }
}
```
