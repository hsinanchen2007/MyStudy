### 解题思路
这位仁兄写得很好了：
https://www.jianshu.com/p/880272af8dc0

### 代码

```swift
class MyStack {
    var stack = [Int]()
    /** Initialize your data structure here. */
    init() {
        
    }
    
    /** Push element x onto stack. */
    func push(_ x: Int) {
        self.stack.append(x)
    }
    
    /** Removes the element on top of the stack and returns that element. */
    func pop() -> Int {
        return self.stack.popLast()!
    }
    
    /** Get the top element. */
    func top() -> Int {
        return self.stack.last!
    }
    
    /** Returns whether the stack is empty. */
    func empty() -> Bool {
        if (self.stack.count <= 0) {
            return true
        } else {
            return false
        }
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