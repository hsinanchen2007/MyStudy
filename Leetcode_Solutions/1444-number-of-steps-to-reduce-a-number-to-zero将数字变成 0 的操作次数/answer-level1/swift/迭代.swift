### 解题思路
此处撰写解题思路

### 代码

```swift
class Solution {
    func numberOfSteps (_ num: Int) -> Int {
        
        var num = num
        var count = 0
        
        while num != 0 {
            
            if num % 2 == 0 {
                num /= 2

            } else {
                num -= 1
            }
            
            count += 1

        }
        
        return count
        
    }
}
```