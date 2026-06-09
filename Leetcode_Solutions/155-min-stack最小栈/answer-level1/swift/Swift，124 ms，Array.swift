```swift
class MinStack {

    var cache: [Int] = []
    var cacheMin: Int?
    
    /** initialize your data structure here. */
    init() {
        
    }
    
    func push(_ x: Int) {
        cache.append(x)
        if cacheMin != nil {
            cacheMin = min(cacheMin!, x)
        } else {
            cacheMin = x
        }
    }
    
    func pop() {
        let last = cache.removeLast()
        if last == cacheMin {
            cacheMin = cache.min()
        }
    }
    
    func top() -> Int {
        return cache.last!
    }
    
    func getMin() -> Int {
        return cacheMin!
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * let obj = MinStack()
 * obj.push(x)
 * obj.pop()
 * let ret_3: Int = obj.top()
 * let ret_4: Int = obj.getMin()
 */
```