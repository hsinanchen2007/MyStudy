1. 把每个数据和他的索引关联起来，方便构造斐波那契数列的时候判断
2. 枚举所有可能的斐波那契数列的前两项，保存已经使用过的数对，用以较少不必要的构建。


```swift
extension Array where Element == Int {
    func mapNumToIndex() -> [Int:Int] {
        var ans: [Int:Int] = [:]
        for i in 0..<count {
            ans[self[i]] = i
        }
        return ans
    }
}
class Solution {
    func lenLongestFibSubseq(_ A: [Int]) -> Int {
        var ans = 0
        let length = A.count
        let numToIndex = A.mapNumToIndex()
        let maxEle = A.last!
        var visited = Set<[Int]>()
        
        func constructFibonacciSubsequence(_ first: Int, _ second: Int, _ length: Int)  {
            guard let index = numToIndex[first + second] else {
                ans = max(ans, length)
                return
            }
            visited.insert([second,A[index]])
            constructFibonacciSubsequence(second, A[index], length  + 1)
        }
        
        for i in 0..<(length - 2) {
            for j in (i + 1)..<(length - 1) {
                if A[i] + A[j] <= maxEle {
                    if let index = numToIndex[A[i] + A[j]] {
                        if !visited.contains([A[i],A[j]]) {
                            visited.insert([A[i],A[j]])
                            constructFibonacciSubsequence(A[j], A[index], 3)
                        }
                    }
                }
            }
        }
        return ans
    }
}
```
