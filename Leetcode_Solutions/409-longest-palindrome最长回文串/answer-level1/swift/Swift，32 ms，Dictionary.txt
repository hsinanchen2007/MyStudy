```swift
 class Solution {
     func longestPalindrome(_ s: String) -> Int {
        var dict = [Character : Int]()
        for char in s {
            if dict.keys.contains(char) {
                dict[char]! += 1
            } else {
                dict.updateValue(1, forKey: char)
            }
        }
        var sum = 0
        var sigMark = false
        for item in dict {
            if (item.value % 2) != 0 {
                sum += (item.value - 1)
                sigMark = true
            } else {
                sum += item.value
            }
        }
        if sigMark {
            sum += 1
        }
        return sum
     }
 }
```