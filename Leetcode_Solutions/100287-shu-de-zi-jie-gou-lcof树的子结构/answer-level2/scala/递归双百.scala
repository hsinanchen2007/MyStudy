### 解题思路

先用一个递归函数遍历二叉树，然后用另外一个递归函数判断这两个子树是否相等。

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
  def isSubStructure(A: TreeNode, B: TreeNode): Boolean = {
    if (B == null) false
    else recursion(A, B)
  }

  def isEqual(A: TreeNode, B: TreeNode): Boolean = {
    if (B == null) true
    else if (A == null && B != null) false
    else {
      (A.value == B.value) && isEqual(A.left, B.left) && isEqual(A.right, B.right)
    }
  }

  def recursion(A: TreeNode, B: TreeNode): Boolean = {
    if (A == null)  false
    else {
      isEqual(A, B) || recursion(A.left, B) || recursion(A.right, B)
    }
  }
}
```