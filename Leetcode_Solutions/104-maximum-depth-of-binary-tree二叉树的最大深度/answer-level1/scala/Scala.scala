/**
 * Definition for a binary tree node.
 * class TreeNode(var _value: Int) {
 *   var value: Int = _value
 *   var left: TreeNode = null
 *   var right: TreeNode = null
 * }
 */
object Solution {
    def maxDepth(root: TreeNode): Int = {
        if (root == null) {
      0
    } else {
      val left_depth = maxDepth(root.left)
      val right_depth = maxDepth(root.right)
      java.lang.Math.max(left_depth, right_depth) + 1
    }
    }
}