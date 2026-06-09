### 解题思路
此处撰写解题思路

### 代码

```swift
class MyStack {

    var stack: Array<Int>
    
    /** Initialize your data structure here. */
    init() {
        stack = []
    }
    
    /** Push element x onto stack. */
    func push(_ x: Int) {
        stack.append(x)
    }
    
    /** Removes the element on top of the stack and returns that element. */
    func pop() -> Int {
        return stack.removeLast()
    }
    
    /** Get the top element. */
    func top() -> Int {
        return stack.last!
    }
    
    /** Returns whether the stack is empty. */
    func empty() -> Bool {
        return stack.isEmpty
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