### 解题思路
不是任天堂的那个switch..

### 代码

```swift
class Solution {
    func lemonadeChange(_ bills: [Int]) -> Bool {
        
        //定义三个变量分别记录收到的三种硬币的数量（当然你也可以完全不去记录面值为20的硬币
        var coin5 = 0
        var coin10 = 0
        var coin20 = 0
        
        //遍历输入数组，使用switch针对每位顾客收钱找零，如果库存硬币无法支持找零则返回false
        for coin in bills {
            
            switch coin {
            case 5:
                coin5 += 1
            case 10:
                if coin5 >= 1 {
                    coin5 -= 1
                    
                    coin10 += 1
                } else {
                    return false
                }
            case 20:
                if coin10 >= 1 && coin5 >= 1 {
                    coin10 -= 1
                    coin5 -= 1
                    
                    coin20 += 1
                }
                else if coin5 >= 3 {
                    coin5 -= 3
                    
                    coin20 += 1
                }
                else {
                    return false
                }
            default:
                print("???")
            }
        }

        return true
    }
}
```