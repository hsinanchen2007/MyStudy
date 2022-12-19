循环中的判断条件中的判断值都是定值，因此不必每次循环的时候都计算一起，可以放在之前统一计算出来。

```
    func reverse(_ x: Int) -> Int {
        var X = x
        let INT_MAX = Int(pow(2.0, 31.0) - 1)
        let INT_MIN = Int(-pow(2.0, 31.0))
        let INT_MAX_LAST = INT_MAX % 10
        let INT_MIN_LAST = INT_MIN % 10
        let INT_MAX_PRE = INT_MAX / 10
        let INT_MIN_PRE = INT_MIN / 10
        var result = 0
        var pop = 0
        while X != 0 {
            pop = X % 10
            X /= 10
            if result > INT_MAX_PRE || (result == INT_MAX_PRE && pop > INT_MAX_LAST) {
                return 0
            }
            if result < INT_MIN_PRE || (result == INT_MIN_PRE && pop < INT_MIN_LAST) {
                return 0
            }
            result = result * 10 + pop
        }
        return result
    }
```
