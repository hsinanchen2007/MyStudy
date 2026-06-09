### Stack的关键点是先进后出(LIFO)
Stack就像一个桶，先放入的后出去，后放入的先出去，所以可以直接使用数组来实现

### 代码

```swift
class MyStack {
    // 初始化一个数组
    var list = [Int]()
    /** Initialize your data structure here. */
    init() {

    }
    
    /** Push element x onto stack. */
    func push(_ x: Int) {
        // 如果数组为空，直接add
        if list.count == 0 {
            list.append(x)
        } else {
            // 如果不为空，添加到第0位
            list.insert(x, at: 0)
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    func pop() -> Int {
        // 删除0个元素
        return list.remove(at:0)
    }
    
    /** Get the top element. */
    func top() -> Int {
        // 顶部就是第一个元素
        return list.first ?? 0
    }
    
    /** Returns whether the stack is empty. */
    func empty() -> Bool {
        // 数组为空时，Stack就为空
        return list.isEmpty
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