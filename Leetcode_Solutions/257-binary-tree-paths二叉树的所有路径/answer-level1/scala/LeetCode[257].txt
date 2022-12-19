```
object Solution {
  def binaryTreePaths(root: TreeNode): List[String] = {
    if (root == null) return Nil
    if (root.left == null && root.right == null) return List(root.value.toString)
    val strings: List[String] = binaryTreePaths(root.left) ::: binaryTreePaths(root.right)
    strings.map(x => root.value.toString + "->" + x)
  }
```
