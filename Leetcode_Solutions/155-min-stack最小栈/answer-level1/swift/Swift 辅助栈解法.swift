# 简单分析

题目比较简单，在更新最小值的时候，旧的最小值是不能丢弃的，因为在进行 `pop` 操作的时候，我们很可能需要还原到上一个最小值，于是需要使用一种数据结构保存出现过的所有最小值。所以，除了主栈之外，额外使用一个辅助栈保存最小值，在`push`和`pop`操作的时候对两个栈进行同步。

# 使用辅助栈实现
使用辅助栈的算法实现。这里为了简单对 optional值 使用了 `force cast`。

``` swift
class MinStack {
    
    private var values: [Int] = []
    
    private var minValues: [Int] = []
    
    /** initialize your data structure here. */
    init() {}
    
    func push(_ x: Int) {
        values.append(x)
        let minValue = minValues.last
        if minValue == nil || x <= minValue! {
            minValues.append(x)
        }
    }
    
    func pop() {
        let minValue = minValues.last!
        let x = values.removeLast()
        
        if x == minValue {
            minValues.removeLast()
        }
    }
    
    func top() -> Int {
        return values.last!
    }
    
    func getMin() -> Int {
        return minValues.last!
    }
}
```

# 不使用辅助栈实现

数据结构是相当灵活的，我们可以稍作改进。`push` 和 `pop` 操作会改变栈的状态，每一个状态都对应着一个栈的最小值，如果在 `push` 的时候把当前状态的最小值一同压入栈中，就不需要使用额外的辅助栈了，而且代码也变得更加简洁。

```swift
class MinStack {
    
    typealias Item = (value: Int, prevMin: Int)
    
    private var items: [Item] = []
    
    /** initialize your data structure here. */
    init() {}
    
    func push(_ x: Int) {
        if let lastItem = items.last {
            items.append((value: x, prevMin: min(x, lastItem.prevMin)))
        } else {
            items.append((value: x, prevMin: x))
        }
    }
    
    func pop() {
        items.removeLast()
    }
    
    func top() -> Int {
        return items.last!.value
    }
    
    func getMin() -> Int {
        return items.last!.prevMin
    }
}
```