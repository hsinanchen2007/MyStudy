
### 代码

```swift
class MyStack {
    var deque: [Int]
    /** Initialize your data structure here. */
    init() {
        self.deque = [Int]()
    }
    
    /** Push element x onto stack. */
    func push(_ x: Int) {
        self.deque.append(x)
    }
    
    /** Removes the element on top of the stack and returns that element. */
    func pop() -> Int {
        return self.deque.removeLast()
    }
    
    /** Get the top element. */
    func top() -> Int {
        return self.deque.last ?? 0
    }
    
    /** Returns whether the stack is empty. */
    func empty() -> Bool {
        return self.deque.count == 0 
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