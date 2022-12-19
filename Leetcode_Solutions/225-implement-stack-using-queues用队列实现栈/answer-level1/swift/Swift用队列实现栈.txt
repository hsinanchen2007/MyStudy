### 解题思路
限于编译器不支持范型, 故只能认为栈元素为整型.

### 代码

```swift
class MyStack {

    var innerQueue = [Int]()
    
    init() {}
    
    /** Push element x onto stack. */
    func push(_ x: Int) {
        innerQueue.append(x)
    }
    
    /** Removes the element on top of the stack and returns that element. */
    func pop() -> Int {
        return innerQueue.removeLast()
    }
    
    /** Get the top element. */
    func top() -> Int {
        return innerQueue.last ?? 0
    }
    
    /** Returns whether the stack is empty. */
    func empty() -> Bool {
        return innerQueue.isEmpty
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