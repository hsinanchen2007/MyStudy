### 解题思路

先统计然后再取出需要的数

### 代码

```swift
class Solution {
   func getLeastNumbers(_ arr: [Int], _ k: Int) -> [Int] {
        
        if k == 0 {
            return []
        }
        
        var numsCount = Array.init(repeating: -1, count: 10000)

        var sortArr = arr
        
        for i in 0 ..< sortArr.count  {
            
            let tVal = sortArr[i]
            if numsCount[tVal] != -1 {
                numsCount[tVal]  = numsCount[tVal]  + 1
            } else {
                numsCount[tVal]  = 1
            }
        }
        
        var total = k
        var returnArray = [Int]()
        for index in 0 ..< numsCount.count {
            
            let val = numsCount[index]
            if val < 0 {
                continue
            }
            
            if total - val >= 0 {
                total = total - val
                for _ in 0 ..< val {
                    returnArray.append(index)
                }
            } else {
                for _ in 0 ..< val {
                    if total > 0 {
                        total = total - 1
                        returnArray.append(index)
                    }
                    
                }
            }
        }
        return returnArray
        
    }
}
```