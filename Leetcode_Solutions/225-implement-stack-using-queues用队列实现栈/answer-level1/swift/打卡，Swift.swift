```
class MyStack {
    private var queue: [Int] = []

    init() {}
    
    func push(_ x: Int) {
        var temp = [x]
        while !queue.isEmpty {
            temp.append(queue.removeFirst())
        }
        queue = temp
    }
    
    func pop() -> Int {
        return queue.removeFirst()
    }
    
    func top() -> Int {
        return queue[0]
    }
    
    func empty() -> Bool {
        return queue.isEmpty
    }
}
```
