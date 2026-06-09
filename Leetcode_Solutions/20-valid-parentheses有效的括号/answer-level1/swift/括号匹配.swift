### 解题思路
堆栈 FILO
括号成对出现,当压进去的和上一个是一对,则不压栈,且弹出上一个
当最后站内什么都没有的时候 说明全部成双成对

### 代码

```swift
class Solution {
    func isValid(_ s: String) -> Bool {
        // 利用堆栈 思想
    
        let ood = s.count % 2
        if ood != 0  {
            return false
        }
        
        // '('，')'，'{'，'}'，'['，']'
        var tempArr = [Character]()
        for c in s {
            switch c {
            case "(","{","[":
                tempArr.append(c)
                
            case ")":
                if tempArr.popLast() != "("  {
                    return false
                }
                
            case "}":
                if tempArr.popLast() != "{"  {
                    return false
                }
                
            case "]":
                if tempArr.popLast() != "["  {
                    return false
                }
                
            default:
                break
            }
        }
        if tempArr.count == 0 {
            return true
        }else{
            return false
        }
    }
}
```