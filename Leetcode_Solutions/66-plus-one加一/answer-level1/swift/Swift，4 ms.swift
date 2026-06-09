```swift
class Solution {
    func plusOne(_ digits: [Int]) -> [Int] {
        var index = digits.count - 1
        var ans = [Int](digits)
        while index > -1 {
            let value = ans[index]
            if value != 9 {
                ans[index] = value + 1
                break   
            }
            ans[index] = 0
            index -= 1
        }
        if index == -1 {
            ans.insert(1, at: 0)
        }
        return ans
    }
}

```