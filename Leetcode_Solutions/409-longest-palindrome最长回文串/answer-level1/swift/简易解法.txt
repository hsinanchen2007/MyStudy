### 解题思路
比较挫的方法，主要是需要找到是否存在唯一一个单数。如果存在则所有双数直接加上，不存在的时候需要单数其中一个抵上。其他单数均减一

### 代码

```swift
class Solution {
func longestPalindrome(_ s: String) -> Int {
        
        var dic = [String: Int]()
        
        for char in s {
            if let val = dic[String(char)] {
                dic.updateValue((val + 1), forKey: String(char))
            } else {
                dic[String(char)] = 1
//                dic.setValue(1, forKey: String(char))
            }
        }
        
        var haveSigleMiddleValue = false
        
        var total = 0
        
        for (key,val) in dic {
            
            let count = val
            if count == 1 {
                haveSigleMiddleValue = true
            } else {
                if count % 2 == 0 {
                    total = total + count
                }
            }
        }
        
        var haveMiddleValue = false
        
        for (key,val) in dic {
            
            let count = val
            
            if count % 2 != 0 && count != 1  {
                
                if haveSigleMiddleValue == true {
                    total = total + (count - 1)
                } else {
                    if haveMiddleValue == false {
                        total = total + count
                        haveMiddleValue = true
                        haveSigleMiddleValue = true
                    }
                }
            }
        }
        
        if haveSigleMiddleValue && !haveMiddleValue {
            total = total + 1
        }
        
        
        return total
    }
}
```