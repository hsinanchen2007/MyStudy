```
object Solution {
  def depth(root: TreeNode): Int = {
    if (root == null) return 0
    else 1 + math.max(depth(root.left), depth(root.right))
  }

  def diameterOfBinaryTree(root: TreeNode): Int = {
    if (root == null) return 0
    val r = depth(root.left) + depth(root.right)
    List(r, diameterOfBinaryTree(root.left), diameterOfBinaryTree(root.right)).max
  }
}
```
