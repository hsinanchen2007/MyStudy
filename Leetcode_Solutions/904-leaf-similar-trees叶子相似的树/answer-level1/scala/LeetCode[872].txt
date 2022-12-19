```
object Solution {
  def dfs(root: TreeNode, buffer: scala.collection.mutable.ArrayBuffer[Int]): Unit = {
    if (root == null) return
    dfs(root.left, buffer)
    if (root.left == null && root.right == null) buffer += root.value
    dfs(root.right, buffer)
  }

  def leafSimilar(root1: TreeNode, root2: TreeNode): Boolean = {
    import scala.collection.mutable.ArrayBuffer
    val buf1 = new ArrayBuffer[Int]()
    val buf2 = new ArrayBuffer[Int]()
    dfs(root1, buf1)
    dfs(root2, buf2)
    buf1 == buf2
  }
}
```
