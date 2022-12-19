```
class Solution {
    func findComplement(_ num: Int) -> Int {
        var temp = num
        var count = 0
        var n:Int = 0
        while temp > 0 {
            if temp % 2 == 0 {
                n += Int(pow(2.0, Float(count)))
            }
            temp /= 2
            count += 1
        }
        return  n
    }
}
```