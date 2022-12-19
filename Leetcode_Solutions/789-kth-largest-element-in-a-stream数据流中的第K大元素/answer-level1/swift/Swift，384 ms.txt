```swift
extension RandomAccessCollection {
    func insertIndex(_ block: (Element) -> Bool) -> Index {
        var slice: SubSequence = self[...]
        while !slice.isEmpty {
            let middle = slice.index(slice.startIndex, offsetBy: slice.count / 2)
            slice = block(slice[middle]) ? slice[index(after: middle)...] : slice[..<middle]
        }
        return slice.startIndex
    }
}

class KthLargest {

    var cache: [Int] = []
    var k: Int
    
    init(_ k: Int, _ nums: [Int]) {
        self.k = k
        cache = nums.sorted(by: {$0 > $1})
    }
    
    func add(_ val: Int) -> Int {
        cache.insert(val, at: cache.startIndex.distance(to: cache.insertIndex({ val < $0 })))
        return cache[k - 1]
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * let obj = KthLargest(k, nums)
 * let ret_1: Int = obj.add(val)
 */
```