### 解题思路

利用栈的后进先出的特性。

因为swift没有栈，利用数组来模拟一个栈，将元素插入数组头部为入栈操作，移除数组头部元素为出栈。

1. 先将root入栈
2. 循环执行，直至栈为空
弹出栈顶top，将值存入结果数组
将top右子节点入栈
将top左子节点入栈


### 代码

```swift
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.left = nil
 *         self.right = nil
 *     }
 * }
 */
class Solution {
    func preorderTraversal(_ root: TreeNode?) -> [Int] {
        var vars: [Int] = []
        traversalWithNode(root) {
            vars.append($0)
        }
        return vars
    }

    func traversalWithNode(_ node: TreeNode?, _ fn: (Int)->()) {
        var stack: [TreeNode] = []
        if let n = node {
            stack.append(n)
            while !stack.isEmpty {
                let top = stack.removeFirst()
                fn(top.val)
                if let right = top.right {
                    stack.insert(right, at: 0)
                }
                if let left = top.left {
                    stack.insert(left, at: 0)
                }
            }
        }
    }
}
```