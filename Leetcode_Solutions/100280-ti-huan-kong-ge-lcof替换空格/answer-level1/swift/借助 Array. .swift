遍历字符串数组, 如果字符不为空格, 则直接追加到数组;
如果是空格, 追加 “%20”. 

### 代码

```swift
class Solution {
    func replaceSpace(_ s: String) -> String {
        if s.isEmpty { return s }
    
        var result = [String]()
        
        for str in s {
            if str == " " {
                result.append("%20")
            } else {
                result.append(String(str))
            }
        }
        
        var resultString: String = ""
        for i in result {
            resultString += i
        }
        return resultString
    }
}
```