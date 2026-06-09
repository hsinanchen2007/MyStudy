
单调栈
```swift
class Solution {
    func dailyTemperatures(_ T: [Int]) -> [Int] {
        let n = T.count
        if n == 0 {
            return []
        }
        var stack = [Int]()
        var res = Array(repeating: 0, count: n)
        
        var i = n-1
        while i >= 0 {
            let ti = T[i]
            while stack.count > 0 && T[stack[0]] <= ti {
                stack.removeFirst()
                
            }
            stack.insert(i, at: 0)
            if stack.count > 1 {
                res[i] = stack[1] - i
            }else{
                res[i] = 0
            }
            i-=1
        }
        return res
    }
}
```