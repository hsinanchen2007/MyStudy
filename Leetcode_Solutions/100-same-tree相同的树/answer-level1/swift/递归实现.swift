**思路**

- 递归
- 时间复杂度：O(n)，n 为树的节点个数

```swift
public func isSameTree(_ p: TreeNode?, _ q: TreeNode?) -> Bool {
    if p == nil && q == nil { return true }
    return p?.val == q?.val && 
            isSameTree(p?.left, q?.left) && 
            isSameTree(p?.right, q?.right)
}
```
