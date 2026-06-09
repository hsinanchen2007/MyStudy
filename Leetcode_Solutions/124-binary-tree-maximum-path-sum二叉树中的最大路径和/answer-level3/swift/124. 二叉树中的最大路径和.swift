### 最大路径和可以是

- 左子树的最大和
- 右子树的最大和
- 左边一条直线路径/0 + 当前节点 + 右边一条直线路径/0

所以递归函数需要返回一个(singlePath: Int, maxPath: Int)
同时利用当node == nil 时，返回（0，Int.min）来巧妙的保证了肯定能包含一个节点

```swift
class Solution {
  func maxPathSum(_ root: TreeNode?) -> Int {
    return getPathSum(root).maxPath
  }
  
  private func getPathSum(_ root: TreeNode?) -> (singlePath: Int, maxPath: Int) {
    guard let root = root else {
      return (0, Int.min)
    }
    
    let left = getPathSum(root.left)
    let right = getPathSum(root.right)
    
    var singlePath = max(left.singlePath, right.singlePath) + root.val
    singlePath = max(singlePath, 0)
    
    let maxPath = max(left.maxPath,
                      right.maxPath,
                      left.singlePath + right.singlePath + root.val)
    return (singlePath, maxPath)
  }
}
```
