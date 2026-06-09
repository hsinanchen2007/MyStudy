### 解题思路

用堆栈数组来操作

### 代码

```swift
class Solution {
func maxDepthAfterSplit(_ seq: String) -> [Int] {
        
        var arr = Array.init(repeating: 0, count: seq.count)
        var currentVal = 0 // A
        var stackArray = Array<Character>.init()
        
        let splitedCharArr:[Character] = Array(seq)
        
        for index in 0 ..< splitedCharArr.count {
            let val = splitedCharArr[index]
            
            if val == "(" {
                
                if stackArray.count > 0 {
                    currentVal = currentVal == 0 ? 1 : 0
                }
                
                arr[index] = currentVal
                stackArray.append(val)
                
//                stackArray.append(val)
            } else {
                stackArray.append(val)
                arr[index] = currentVal
                stackArray.removeLast()
                stackArray.removeLast()
                currentVal = currentVal == 0 ? 1 : 0
                
            }
        }
        
        return arr
    }
}
```