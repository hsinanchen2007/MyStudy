```
class Solution {
    func hammingWeight(_ n: Int) -> Int {
        if n == 0 {
            return 0
        }
        var n = n
        var count = 0
        while n != 0 {
            n = n & (n - 1) //去除最低位的1.
            count += 1
        }
        return count
    }
}
```