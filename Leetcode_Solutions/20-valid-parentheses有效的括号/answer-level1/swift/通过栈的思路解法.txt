### 解题思路

通过栈的思路解法

![image.png](https://pic.leetcode-cn.com/32fad0250f7c7efaede9e4a7ae1ae9ea3bcfea2de2bcc6adc93ce72ae3d09da4-image.png)

### 代码

```swift
class Solution {
    func isValid(_ s: String) -> Bool {
        
        let map = [
            String.Element("(").asciiValue! : String.Element(")").asciiValue! ,
            String.Element("[").asciiValue! : String.Element("]").asciiValue!,
            String.Element("{").asciiValue! : String.Element("}").asciiValue!
        ]

        var stack = Array<UInt8>()
        
        for ele in s {
            let ascii = ele.asciiValue!
            if map[ascii] != nil {
                stack.append(ascii)
            }else if stack.isEmpty {
                return false
            }else if map[stack.last!] == ascii {
                _ = stack.popLast()
            }else{
                return false
            }
            
        }
        return stack.isEmpty
    }
}

```