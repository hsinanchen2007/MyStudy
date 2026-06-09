### 解题思路

算这个数值的集合，主要是确定上限max，很好理解，它就是 10^n - 1 ,有了这个上限，直接输出1...N 即可

### 代码

#### 一行代码实现

```swift
import Foundation

class Solution {
    func printNumbers(_ n: Int) -> [Int] {
        return Array.init(1..<Int(pow(10.0, Double(n))))
    }
}
```

#### 常规实现

```swift
import Foundation

class Solution {
    func printNumbers(_ n: Int) -> [Int] {
        
        var res:[Int] = []
        let max:Int = Int(pow(10.0, Double(n)))
        for i in 1..<max {
            res.append(i)
        }
        return res
    }
}
```