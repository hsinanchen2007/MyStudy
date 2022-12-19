```
class Solution {
    
    func method(_ digits: [Int]) -> [Int] {
        var mutable = digits
        let lastIndex = digits.count - 1
        if digits[lastIndex] != 9 {
            mutable[lastIndex] = digits[lastIndex] + 1
            return mutable
        } else {
            mutable.removeLast()
            if mutable.count == 0 {
                return [1, 0]
            } else {
                return method(mutable) + [0]
            }
        }
    }
    
    func plusOne(_ digits: [Int]) -> [Int] {
        var allNine = true
        for digit in digits {
            if digit == 9 {
                continue
            } else {
                allNine = false
                break
            }
        }
        if allNine {
            var array: [Int] = []
            for (index, _) in digits.enumerated() {
                if index == 0 {
                    array.append(1)
                } else {
                    array.append(0)
                }
            }
            array.append(0)
            return array;
        } else {
            return method(digits)
        }
    }
}
```
