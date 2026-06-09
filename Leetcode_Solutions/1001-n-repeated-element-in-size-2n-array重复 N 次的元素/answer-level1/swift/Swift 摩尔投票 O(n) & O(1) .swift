
对前面的2N-1个数进行摩尔投票的同时检查是否可能是最后一个数。

```swift
class Solution {

    func repeatedNTimes(_ A: [Int]) -> Int {
        let last = A.last!
        var vote = 0
        var result = 0

        for i in 0..<A.count - 1 {
            if A[i] == last {
                return last
            } else if vote == 0 {
                vote = 1
                result = A[i]
            } else if result == A[i] {
                vote = vote + 1
            } else {
                vote = vote - 1
            }
        }

        return result
    }
}
```