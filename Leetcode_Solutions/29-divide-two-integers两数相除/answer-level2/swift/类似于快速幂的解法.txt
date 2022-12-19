```
class Solution {
    func divide(_ dividend: Int, _ divisor: Int) -> Int {
        if dividend == Int32.min && divisor == 1 {
            return Int(Int32.min)
        }
       var r:Int32 = 0
        var aDividend = -abs(dividend)
        let aDivisor = -abs(divisor)
        var moveStep = 0
        while aDividend <= aDivisor<<moveStep {
            if r == Int32.max {
                break
            }
            aDividend -= aDivisor<<moveStep
            if Int32.max - r < 1<<moveStep {
                r = Int32.max
                break
            } else {
                r += 1<<moveStep
            }
            moveStep += 1
            if aDividend > aDivisor<<moveStep {
                moveStep = 0
            }
        }
        if (dividend > 0 && divisor < 0 || dividend < 0 && divisor > 0) {
            return Int(-r)
        } else {
            return Int(r)
        }
    }
}
```
