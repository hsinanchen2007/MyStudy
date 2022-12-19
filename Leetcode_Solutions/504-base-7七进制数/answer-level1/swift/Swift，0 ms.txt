```swift
class Solution {
    func convertToBase7(_ num: Int) -> String {
        if num == 0 {
            return "0"
        } else if num < 0 {
            return "-\(convertToBase7(-num))"
        } else {
            var num = num
            var ans = ""
            while num > 0 {
                ans += "\(num % 7)"
                num /= 7
            }
            return String(ans.reversed())
        }
    }
}
```