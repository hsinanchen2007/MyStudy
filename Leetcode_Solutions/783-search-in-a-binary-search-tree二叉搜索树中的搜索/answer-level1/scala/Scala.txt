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
    def searchBST(root: TreeNode, `val`: Int): TreeNode = {
     if (root == null || (root.value == `val`)) return root
      if (root.value > `val`) searchBST(root.left, `val`)
    else searchBST(root.right, `val`)   
    }
}
```