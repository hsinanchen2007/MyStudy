### 解题思路

只要知道栈的结构即可轻松使用线性数组来模拟

### 代码

```swift
class MyStack {
    
    public var list: Array<Int> = [];

    /** Initialize your data structure here. */
    init() {

    }
    
    /** Push element x onto stack. */
    func push(_ x: Int) {
        list.append(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    func pop() -> Int {
        return list.removeLast();
    }
    
    /** Get the top element. */
    func top() -> Int {
        return list.last ?? 0
    }
    
    /** Returns whether the stack is empty. */
    func empty() -> Bool {
        return list.isEmpty
    }
}
```