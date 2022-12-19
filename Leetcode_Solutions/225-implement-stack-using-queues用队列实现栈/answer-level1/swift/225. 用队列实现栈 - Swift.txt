1. 用数组来模拟一个队列
2. 入栈时，执行`array.append()`方法，出栈时，执行`array.removeList()`方法
3. 当队列为空时，如果执行出栈操作，则报错，示例代码如下：

``` swift
class MyStack {
    private var array: [Int] = []
    private var size: Int = 0
    private let domain = "com.dev.cy"
    private let code = -1
    /** Initialize your data structure here. */
    init() { }

    /** Push element x onto stack. */
    func push(_ x: Int) {
        array.append(x)
        size += 1
    }

    /** Removes the element on top of the stack and returns that element. */
    @discardableResult
    func pop() throws -> Int {
        if empty() { throw NSError(domain: domain, code: code, userInfo: nil) }
        size -= 1
        return array.removeLast()
    }

    /** Get the top element. */
    @discardableResult
    func top() throws -> Int {
        if empty() { throw NSError(domain: domain, code: code, userInfo: nil) }
        return array[size - 1]
    }

    /** Returns whether the stack is empty. */
    func empty() -> Bool {
        return size == 0
    }
}
```
