```scala
import scala.collection.mutable.ListBuffer

object Solution {
  def recoverTree(root: TreeNode): Unit = {
    val node = new ListBuffer[TreeNode]
    val v = new ListBuffer[Int]
    func(root, node, v)
    val t = v.sorted
    node.indices.foreach(i => node(i).value = t(i))
  }

  def func(root: TreeNode, node: ListBuffer[TreeNode], v: ListBuffer[Int]): Unit = {
    if (root == null) return
    func(root.left, node, v)
    node.append(root)
    v.append(root.value)
    func(root.right, node, v)
  }
}
```
