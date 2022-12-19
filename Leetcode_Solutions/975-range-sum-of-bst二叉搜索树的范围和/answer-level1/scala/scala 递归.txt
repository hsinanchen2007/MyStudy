```scala
object Solution {
  def rangeSumBST(root: TreeNode, L: Int, R: Int): Int = {
    if (root == null) return 0
    if (root.value < L) return rangeSumBST(root.right, L, R)
    if (root.value > R) return rangeSumBST(root.left, L, R)
    root.value + rangeSumBST(root.left, L, R) + rangeSumBST(root.right, L, R)
  }
}
```
