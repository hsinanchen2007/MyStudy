```
class MyStack {
    var array = [Int]()   
    /** Initialize your data structure here. */
    init() {
    }
    
    /** Push element x onto stack. */
    func push(_ x: Int) {
        array.append(x)
    }
    
    /** Removes the element on top of the stack and returns that element. */
    func pop() -> Int {
        return array.isEmpty ? -1 : array.popLast()!
    }
    
    /** Get the top element. */
    func top() -> Int {
        return array.isEmpty ? -1 : array.last!
    }
    
    /** Returns whether the stack is empty. */
    func empty() -> Bool {
        return array.isEmpty
    }
}
```
