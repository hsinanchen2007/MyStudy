### 解题思路
 等差数列, a1, 差为1, 长度为l
 则target = 1/2 * l * (a+ a+l-1)
 a = (2*target + l -l^2) / (2l)
 length范围 2...lmax
 对应       amax...1 , 当a=1时,解二次方程得lmax
 lmax ...2 遍历验证
 l带入求a, a为整数则可以

### 代码

```swift
class Solution {
    func findContinuousSequence(_ target: Int) -> [[Int]] {
        let lmax:Int = {
            return Int((pow(Double(1+8*target), 0.5) - 1.0)/2.0)
        }()
        if lmax < 2 {
            return []
        }
        
        var result:[[Int]] = []
        
        let range = (2...lmax).reversed()
        let baseArr = Array(0..<lmax)
        
        for l in range {
            let x = 2*target + l - l*l
            let y = 2*l
            
            if x%y == 0 {
                let a = x/y
                result.append(baseArr[0..<l].map{$0+a})
            }
        }
        return result
    }
}
```