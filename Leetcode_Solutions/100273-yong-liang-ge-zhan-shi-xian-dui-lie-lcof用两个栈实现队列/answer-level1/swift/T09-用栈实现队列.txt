### 解题思路
由于Swfit中没有栈和队列的概念，直接用数组实现即可。

### 代码

```swift
class CQueue {
    var stack: [Int]

    init() {
        self.stack = []
    }
    
    func appendTail(_ value: Int) {
        self.stack.insert(value, at: stack.endIndex)
    }
    
    func deleteHead() -> Int {
        if self.isEmpty {
            return -1
        }

        return self.stack.remove(at: 0)

    }
}

```