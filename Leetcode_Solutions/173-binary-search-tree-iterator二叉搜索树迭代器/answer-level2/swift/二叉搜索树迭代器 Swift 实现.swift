最简单的方式就是初始化时候进行中序遍历，然后缓存结果，在调用`next()`时从缓存中查找，但是这样初始化操作的成本太大。为了增加迭代器的效率，尽可能只在需要的时候进行计算。可以使用一个栈，每当调用`next()`的时候，将树中的一些节点压入栈中，总是使得栈顶元素是下一个最小值。

```swift []
class BSTIterator {
        
    private var stack: [TreeNode] = []

    init(_ root: TreeNode?) {
        guard let root = root else { return }
        preload(root)
    }
    
    private func preload(_ node: TreeNode) {
        var current: TreeNode? = node
        while current != nil {
            stack.append(current!)
            current = current!.left
        }
    }
    
    /** @return the next smallest number */
    func next() -> Int {
        let smallest = stack.popLast()!
        
        if let node = smallest.right {
            preload(node)
        }
        
        return smallest.val
    }
    
    /** @return whether we have a next smallest number */
    func hasNext() -> Bool {
        return !stack.isEmpty
    }
}
```