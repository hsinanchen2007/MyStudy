### 解题思路
主队列负责 enqueue
dequeue时，优先辅助队列，如果辅助队列不满足，其次主队列
如果辅助队列为空，主队列不满足，则先把当前元素放到辅助队列里面

### 代码

```swift
class AnimalShelf {
    
    private var primaryQueue = [[Int]]()
    private var supportQueue = [[Int]]()

    init() {}
    
    func enqueue(_ animal: [Int]) {
        primaryQueue.append(animal)
    }
    
    func dequeueAny() -> [Int] {
        if !supportQueue.isEmpty {
            return supportQueue.removeFirst()
        }
        if !primaryQueue.isEmpty {
            return primaryQueue.removeFirst()
        }
        return [-1, -1]
    }
    
    func dequeueDog() -> [Int] {
        if !supportQueue.isEmpty {
            if supportQueue.first?.last == 1 {
                return supportQueue.removeFirst()
            }
        }
        
        while !primaryQueue.isEmpty {
            let first = primaryQueue.removeFirst()
            if first.last == 1 {
                return first
            } else {
                supportQueue.append(first)
            }
        }
        return [-1, -1]
    }
    
    func dequeueCat() -> [Int] {
        if !supportQueue.isEmpty {
            if supportQueue.first?.last == 0 {
                return supportQueue.removeFirst()
            }
        }
        
        while !primaryQueue.isEmpty {
            let first = primaryQueue.removeFirst()
            if first.last == 0 {
                return first
            } else {
                supportQueue.append(first)
            }
        }
        return [-1, -1]
    }
}

/**
 * Your AnimalShelf object will be instantiated and called as such:
 * let obj = AnimalShelf()
 * obj.enqueue(animal)
 * let ret_2: [Int] = obj.dequeueAny()
 * let ret_3: [Int] = obj.dequeueDog()
 * let ret_4: [Int] = obj.dequeueCat()
 */
```