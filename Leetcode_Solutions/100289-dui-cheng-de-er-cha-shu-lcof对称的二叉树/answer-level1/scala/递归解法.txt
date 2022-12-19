### 解题思路

左右对称边递归并判断

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
  def isSymmetric(root: TreeNode): Boolean = {
      helper(root, root)
  }

  def helper(x1: TreeNode, x2: TreeNode): Boolean = {
    if (x1 == null && x2 == null) true
    else if (x1 == null || x2 == null) false
    else {
      (x1.value == x2.value) && helper(x1.left, x2.right) && helper(
        x1.right,
        x2.left
      )
    }

  }
}
```