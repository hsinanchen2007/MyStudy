非常容易理解的反转字符串解法。

class Solution {
    func reverse(_ x: Int) -> Int {
        let xString = String("\(abs(x))".reversed())
        let result = x > 0 ? Int(xString)! : 0 - Int(xString)!
        if result > INT32_MAX || result < Int32.min {
            return 0
        }
        return result
    }
}