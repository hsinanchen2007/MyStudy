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
    def trimBST(root: TreeNode, L: Int, R: Int): TreeNode = {
     if (root == null) return root
    if (root.value < L) return trimBST(root.right, L, R)
    if (root.value > R) return trimBST(root.left, L, R)
    root.left = trimBST(root.left, L, R)
    root.right = trimBST(root.right, L, R)
    root   
    }
}
```