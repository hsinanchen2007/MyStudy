### 解题思路

一般的递归解法

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
    def maxDepth(root: TreeNode): Int = {
        def helper(root: TreeNode, depth: Int): Int = {
            if (root == null) depth
            else {
                math.max(helper(root.left, depth + 1), helper(root.right, depth + 1))
            }
        }
        // 当然也可以用模式匹配
        // def helper2(root: TreeNode, depth: Int): Int = root match {
        //     case null => depth
        //     case _ => math.max(helper2(root.left, depth + 1), helper2(root.right, depth + 1))
        // }
        // helper2(root, 0)
        helper(root, 0)
    }
}
```