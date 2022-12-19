```swift
struct Stack<Element> {
    fileprivate var array: [Element] = []

    mutating func push(_ element: Element) {
        array.append(element)
    }

    mutating func pop() -> Element {
        return array.popLast()!
    }

    func peek() -> Element {
        return array.last!
    }
    
    func size() -> Int {
        return array.count
    }
    
    func isEmpty() -> Bool {
        return array.isEmpty
    }
}

class MyQueue {

    var stackA = Stack<Int>()
    var stackB = Stack<Int>()
    
    func transfer() {
        if stackA.isEmpty() {
            while !stackB.isEmpty() {
                stackA.push(stackB.pop())
            }
        }
    }
    
    /** Initialize your data structure here. */
    init() {
        
    }
    
    /** Push element x to the back of queue. */
    func push(_ x: Int) {
        stackB.push(x)
    }
    
    /** Removes the element from in front of queue and returns that element. */
    func pop() -> Int {
        transfer()
        return stackA.pop()
    }
    
    /** Get the front element. */
    func peek() -> Int {
        transfer()
        return stackA.peek()
    }
    
    /** Returns whether the queue is empty. */
    func empty() -> Bool {
        return stackA.isEmpty() && stackB.isEmpty()
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * let obj = MyQueue()
 * obj.push(x)
 * let ret_2: Int = obj.pop()
 * let ret_3: Int = obj.peek()
 * let ret_4: Bool = obj.empty()
 */
```