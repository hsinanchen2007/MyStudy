我们要保证最有潜力的成为最大值的元素索引留在 deque 中，并转换为需要的 output 数组，所以要做 3 件事

a. 当 deque 中的索引超出 [i-(k-1), i]（k 区间内）时，及时从 deque 头部清理掉
b. 当 a(x) < a(i) 且 x < i 时，a[i] 即将进入 k 分组，所以 a[x] 是没有机会成为最大值的，所以将这样的索引从尾部去除
c. 入队，并且在第一个 k 组遍历结束时，从 deque 头部获取到最大值的索引，并将对应的值添加到保存最大值的 res 数组中

```swift
class Solution {
    func maxSlidingWindow(_ nums: [Int], _ k: Int) -> [Int] {
        /// deque 双端队列法
        let n = nums.count
        var res = [Int]()
        var deque = Deque<Int>()
        for i in 0..<n {
            // a. 如果队列不空且超出 [i-(k-1), i] 区间，则从队头移除队列
            if !deque.isEmpty && deque.peekFront! < i - k + 1 { _ = deque.dequeue() }
            // b. 当 a(x) < a(i) 且 x < i 时，a[i] 即将进入 k 分组，所以 a[x] 是没有机会成为最大值的，所以将这样的索引从尾部去除
            while !deque.isEmpty && nums[deque.peekBack!] < nums[i] { _ = deque.dequeueBack()}
            // 入队
            deque.enqueue(i)
            if let peekFront = deque.peekFront {
                // c.第一个 k 组遍历结束时，从 deque 头部获取到最大值的索引，并将对应的值添加到保存最大值的 res 数组中
                if i >= k - 1 { res.append(nums[peekFront]) }
            }
        }
        return res
    }
}
```
Deque 实现
```swift
public struct Deque<T> {
    // 内部私有容器
    private var array = [T]()
    // 数量
    public var count: Int {
        return array.count
    }
    // 判空
    public var isEmpty: Bool {
        return array.isEmpty
    }
    // 前进队列
    public mutating func enqueue(_ element: T) {
        array.append(element)
    }
    // 后进队列
    public mutating func enqueueFront(_ element: T) {
        array.insert(element, at: 0)
    }
    // 前出队列
    public mutating func dequeue() -> T? {
        if isEmpty {
            return nil
        }
        return array.removeFirst()
    }
    // 后出队列
    public mutating func dequeueBack() -> T? {
        if isEmpty {
            return nil
        }
        return array.removeLast()
    }
    // 前看
    public var peekFront: T? {
        return array.first
    }
    // 后看
    public var peekBack: T? {
        return array.last
    }
}
```