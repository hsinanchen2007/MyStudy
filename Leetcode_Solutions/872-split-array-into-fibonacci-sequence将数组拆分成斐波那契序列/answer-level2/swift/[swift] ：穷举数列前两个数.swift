```swift
class Solution {
    
    var ans = [Int]()
    var chars = [Character]()
    var length = -1
    
    func splitIntoFibonacci(_ S: String) -> [Int] {
        
        length = S.count
        chars = [Character](S)
        
        //要有三个数，每个数至少有一位
        for i in 1...(min(length, 10) - 2) {
            for j in 1...(min(length - i, 10)  - 1) {
                guard self.ans.isEmpty else {
                    return ans
                }
                let previous = String(chars[0..<i])
                let current  = String(chars[i..<(i + j)])
                
                func valid(_ numberStr: String) -> Bool {
                    return numberStr.count == 1 ? true : !numberStr.hasPrefix("0")
                }
                
                if valid(previous) && valid(current) {
                    if let first = Int(previous), first  <= Int32.max, let second = Int(current), second  <=  Int32.max {
                        helper(previous: first, current: second, remainCharsCount: length - i - j, currentFibArray: [first,second])
                    }
                }
            }
        }
        return ans
    }
    
    private func helper(previous: Int, current: Int,remainCharsCount: Int, currentFibArray: [Int])  {
        
        let target = previous + current
        let targetStr = "\(target)"
        let start = length - remainCharsCount
        
        //1.超出范围 2.余下的字符位数少于所需 3.无法匹配
        if target > Int32.max || targetStr.count > remainCharsCount || String(chars[start..<(start + targetStr.count)]) != targetStr {
            return
        }
        
        var fibArrayCopy = currentFibArray
        fibArrayCopy.append(target)
        if remainCharsCount - targetStr.count == 0 {
            ans = fibArrayCopy
            return
        }
        helper(previous: current, current: target, remainCharsCount: remainCharsCount - targetStr.count, currentFibArray: fibArrayCopy)
    }
}
```
