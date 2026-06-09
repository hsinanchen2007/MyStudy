```swift
class Solution {
    func integerReplacement(_ n: Int) -> Int {
        guard n != 1 else {
            return 0
        }
        var nodes = Array<Int>()
        nodes.append(n)
        var visited = Set<Int>()
        var depth = 0
        while !nodes.isEmpty {
            print(nodes)
            let length = nodes.count
            depth += 1
            for _ in 0..<length {
                let node = nodes.removeFirst()
                if  node % 2  == 0 {
                    let val = node >> 1
                    if val == 1 {
                        return depth
                    }
                    if !visited.contains(val) {
                        visited.insert(val)
                        nodes.append(val)
                    }
                } else {
                    var val = node + 1
                    if val == 1 {
                        return depth
                    }
                    if !visited.contains(val) {
                        visited.insert(val)
                        nodes.append(val)
                    }
                    val = node - 1
                    if val == 1 {
                        return depth
                    }
                    if !visited.contains(val) {
                        visited.insert(val)
                        nodes.append(val)
                    }
                }
            }
        }
        return  depth
    }
}
```
