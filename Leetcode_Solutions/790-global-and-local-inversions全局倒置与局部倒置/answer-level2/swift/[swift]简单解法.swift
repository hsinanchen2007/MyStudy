1.局部倒置一定是全局倒置，所以问题转化为判断是否存在非局部倒置的全局倒置

2.额外的全局倒置：假设当前index = i,从index = i+ 2开始全部数据都大于当前数据，则不存在，否则存在。

3.假设N个数据，分别为[0,1,2,...,N - 1]则大于A[i]的数据有 (N - 1 - A[i])个。假设A[i]和A[i + 1]是局部倒置，则从（i + 2）到最后需要大于A[i]的数据(N- 1 - i - 1)个 ，即必须满足 N - 1 - A[i] - 1 >= N - 1 - i - 1,即 A[i] <= i,否则一定存在小于A[i]的数位于index = i + 2之后的位置上。A[i]和A[i + 1]不是局部倒置的情况，推导过程类似。


```swift
class Solution {
    func isIdealPermutation(_ A: [Int]) -> Bool {
        guard A.count > 2 else {
            return  true
        }
        for i in 0..<(A.count - 1) {
            if A[i + 1] > A[i] {
                if A[i] > i {
                    return false
                }
            } else {
                if A[i] > i + 1 {
                    return false
                }
            }
        }
        return true
    }
}
```
