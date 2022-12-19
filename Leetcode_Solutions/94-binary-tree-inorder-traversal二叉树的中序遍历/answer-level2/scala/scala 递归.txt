```scala
object Solution {
  def inorderTraversal(root: TreeNode): List[Int] = {
    if (root == null) List.empty[Int]
    else inorderTraversal(root.left) ++ List(root.value) ++ inorderTraversal(root.right)
  }
}
```
