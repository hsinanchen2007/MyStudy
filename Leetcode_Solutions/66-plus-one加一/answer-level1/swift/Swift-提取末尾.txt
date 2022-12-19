第一次写题解，请各位多指点、包涵。
```swift
func plusOne(_ digits: [Int]) -> [Int] {
    /*
     提取末尾加一，如果有进位，前一位加一。
     期间将所得余数推进栈，最后再与剩余的没有变化的数字拼接。
     注意[9, 9, 9]等各位都为9的特殊情况。
    */
    if digits.count == 0 {
        return digits
    }
    
    var newDigits = digits
    var abortValue = 0
    var stack = [Int]()
    
    repeat {
        abortValue = 1 + newDigits.removeLast()
        stack.insert(abortValue % 10, at: 0)
        if newDigits.count == 0 && abortValue / 10 == 1 { // 例如[9], 需要进位
            stack.insert(1, at: 0)
        }
    } while abortValue % 10 == 0 && newDigits.count > 0
    return newDigits + stack
}
```