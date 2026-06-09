```swift
class Solution {
    func anagramMappings(_ A: [Int], _ B: [Int]) -> [Int] {
        let BCount = B.count
        if BCount < 1 { return [] }
        var indexedB = [(val: Int, index: Int)]()
        for index in 0..<BCount {
            indexedB.append((val: B[index], index: index))
        }
        var ans = [Int]()
        for item in A {
            let index = indexedB.firstIndex(where: { $0.val == item })!
            ans.append(indexedB[index].index)
            indexedB.remove(at: index)
        }
        return ans
    }
}
```