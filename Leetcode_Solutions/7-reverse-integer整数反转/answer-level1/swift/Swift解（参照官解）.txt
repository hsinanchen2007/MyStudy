```
class Solution {
    func reverse(_ x: Int) -> Int {
        var X = x
        let INT_MAX = pow(2.0, 31.0) - 1
        let INT_MIN = -pow(2.0, 31.0)
        var rev = 0
        var pop : (Int)
        while X != 0 {
            pop = X % 10
            X /= 10
            if (rev > Int(INT_MAX / 10) || (rev == Int(INT_MAX / 10) && pop > 7)) {
                return 0
            }
            if (rev < Int(INT_MIN / 10) || (rev == Int(INT_MIN / 10) && pop < -8)) {
                return 0
            }
            rev = rev * 10 + pop
        }
        return rev
    }
}
```
目前这道题目的Swift版本的题解只有一个，与官解的区别在于他的判断条件没有那么复杂。