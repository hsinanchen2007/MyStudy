### 解题思路
只是用数组去实现的Stack, 偷鸡了

### 代码

```swift
class MyStack {

    var arr:[Int] = []
    /** Initialize your data structure here. */
    init() {

    }
    
    /** Push element x onto stack. */
    func push(_ x: Int) {
        arr.append(x)
    }
    
    /** Removes the element on top of the stack and returns that element. */
    func pop() -> Int {
        return arr.popLast()!
    }
    
    /** Get the top element. */
    func top() -> Int {
        return arr.last!
    }
    
    /** Returns whether the stack is empty. */
    func empty() -> Bool {
        return arr.isEmpty
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