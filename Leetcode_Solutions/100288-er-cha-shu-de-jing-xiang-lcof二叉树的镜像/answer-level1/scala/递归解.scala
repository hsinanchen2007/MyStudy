### 解题思路

最基本的递归，构建新节点时交换左右子节点即可。前序遍历，从树底开始翻转。

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
  def mirrorTree(root: TreeNode): TreeNode = {
    if (root == null) 
      null
    else {
      val r = new TreeNode(root.value)
      val left = mirrorTree(root.left)
      val right = mirrorTree(root.right)
      r.left = right
      r.right = left
      r
    }
  }
}
```