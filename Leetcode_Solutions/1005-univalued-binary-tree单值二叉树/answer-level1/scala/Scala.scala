### 解题思路
此处撰写解题思路

### 代码

```scala
/**
 * Definition for a binary tree node.
 * class TreeNode(var _value: Int) {
 *   var value: Int = _value
 *   var left: TreeNode = null
 *   var right: TreeNode = null
 * }
 */
object Solution {
    def isUnivalTree(root: TreeNode): Boolean = {
        if (root == null) {
      return true
    }
    if (root.left != null && root.left.value != root.value) {
      return false
    }
    if (root.right != null && root.right.value != root.value) {
      return false
    }
    isUnivalTree(root.right) && isUnivalTree(root.left)    
    }
}
```