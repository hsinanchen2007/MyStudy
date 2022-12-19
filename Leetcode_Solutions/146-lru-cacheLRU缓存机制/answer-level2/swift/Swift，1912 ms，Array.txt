```swift
class LRUCache {

    var cache: [(key: Int, value: Int)] = []
    private let cacheLen: Int

    init(_ capacity: Int) {
        cacheLen = capacity
        cache.reserveCapacity(capacity)
    }

    func get(_ key: Int) -> Int {
        var indexV: Int?
        for index in 0..<cache.count {
            if cache[index].key == key {
                indexV = index
                break
            }
        }
        if let indexV = indexV {
            let itemV = cache[indexV]
            cache.remove(at: indexV)
            cache.insert(itemV, at: 0)
            return itemV.value
        }
        return -1
    }

    func put(_ key: Int, _ value: Int) {
        var exist: Int?
        for index in 0..<cache.count {
            if cache[index].key == key {
                exist = index
                break
            }
        }
        if let exist = exist {
            cache.remove(at: exist)
        }
        if cacheLen <= cache.count {
            cache.removeLast()
        }
        cache.insert((key: key, value: value), at: 0)
    }
}


/**
 * Your LRUCache object will be instantiated and called as such:
 * let obj = LRUCache(capacity)
 * let ret_1: Int = obj.get(key)
 * obj.put(key, value)
 */


/*
let options: [String] = ["LRUCache","get","put","get","put","put","get","get"]
let values: [[Int]] = [[2],[2],[2,6],[1],[1,5],[1,2],[1],[2]]
let cache: LRUCache = LRUCache( values[0][0] /* 缓存容量 */ );
for (index, option) in options.enumerated() {
    print("index: \(index)")
    switch option {
    case "get":
        print("get(\(values[index][0])): \(cache.get(values[index][0]))")
    case "put":
        print("put([\(values[index][0]), \(values[index][1])])")
        cache.put(values[index][0], values[index][1])
    default:
        break
    }
    print("cache: \(cache.cache)\n")
}
*/
```