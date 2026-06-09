```scala
import scala.collection.mutable
import scala.collection.mutable.ListBuffer

object Solution {
  def rightSideView(root: TreeNode): List[Int] = {
    if (root == null) return List()
    val res = new ListBuffer[Int]()
    val q = new mutable.Queue[TreeNode]()
    q.enqueue(root)
    while (q.nonEmpty) {
      res.append(q.last.value)
      q.indices.foreach(_ => {
        val node = q.front
        q.dequeue
        if (node.left != null) q.enqueue(node.left)
        if (node.right != null) q.enqueue(node.right)
      })
    }
    res.toList
  }
}
```
