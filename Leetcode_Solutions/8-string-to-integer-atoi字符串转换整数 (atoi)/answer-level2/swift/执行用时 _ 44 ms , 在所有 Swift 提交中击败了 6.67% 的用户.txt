### 解题思路
此处撰写解题思路

### 代码

```swift
class Solution {
func myAtoi(_ str: String) -> Int {
        
        let nums:[Character] = ["+","-","0","1","2","3","4","5","6","7","8","9"]
        
        let filterStr =  str.trimmingCharacters(in: .whitespaces)
        let vals = Array.init(filterStr)
        
        if vals.count > 0 {
            let val = vals[0]
            if !nums.contains(val) {
                return 0
            }
        }
        
        var filterArray = Array<String>.init()
        
        for i in 0 ..< vals.count {
            let character = vals[i]
            
           if (character == "+" || character == "-")
                && i > 0 {
                break
            }

            if nums.contains(character) {
                filterArray.append(String(character))
            }  else {
                break
            }
        }
        
        let returnVal = filterArray.joined(separator: "")
        
        guard let douVal = Double(returnVal) else { return 0 }
        
        if douVal > Double(Int32.max) {
            return Int(Int32.max)
        }
        if douVal < Double(Int32.min) {
            return Int(Int32.min)
        }
        
        return Int(douVal)
    }
}
```