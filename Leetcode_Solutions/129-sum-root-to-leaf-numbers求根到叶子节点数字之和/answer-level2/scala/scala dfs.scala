```scala
object Solution {
  def sumNumbers(root: TreeNode): Int = {
    dfs(root, 0)
  }

  def dfs(root: TreeNode, sum: Int): Int = {
    if (root == null) return 0
    val t = sum * 10 + root.value
    if (root.left == null && root.right == null) return t
    dfs(root.left, t) + dfs(root.right, t)
  }
}
```
