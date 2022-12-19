### 解题思路
手动创建一个队列，很多答案都直接用数组创建栈，不知道在想什么...

### 代码

```swift
class Queue {
    private var array = [Int]()
    
    func push(x: Int) {
        array.append(x)
    }
    
    func remove() -> Int {
        return array.removeFirst()
    }
    
    func isEmpty() -> Bool {
        return array.isEmpty
    }

    func size() -> Int {
        return array.count
    }
}

class MyStack {
    
    private var mainQueue = Queue()
    private var tempQueue = Queue()

    /** Initialize your data structure here. */
    init() {

    }
    
    /** Push element x onto stack. */
    func push(_ x: Int) {
        mainQueue.push(x: x)
    }
    
    /** Removes the element on top of the stack and returns that element. */
    func pop() -> Int {
        var remove = -1
        while !mainQueue.isEmpty() {
            let first = mainQueue.remove()
            remove = first
            if mainQueue.isEmpty() {
                continue
            }
            tempQueue.push(x: first)
        }
        while !tempQueue.isEmpty() {
            let first = tempQueue.remove()
            mainQueue.push(x: first)
        }
        return remove
    }
    
    /** Get the top element. */
    func top() -> Int {
        var remove = -1
        while !mainQueue.isEmpty() {
            let first = mainQueue.remove()
            tempQueue.push(x: first)
            remove = first
        }
        while !tempQueue.isEmpty() {
            let first = tempQueue.remove()
            mainQueue.push(x: first)
        }
        return remove
    }
    
    /** Returns whether the stack is empty. */
    func empty() -> Bool {
        return mainQueue.isEmpty()
    }
}


/**
 * Your MyStack object will be instantiated and called as such:
 * let obj = MyStack()
 * obj.push(x)
 * let ret_2: Int = obj.pop()
 * let ret_3: Int = obj.top()
 * let ret_4: Bool = obj.empty()
 */
```