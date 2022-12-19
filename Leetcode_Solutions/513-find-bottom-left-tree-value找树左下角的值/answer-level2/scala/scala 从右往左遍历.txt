```scala
import scala.collection.mutable

object Solution {
  def findBottomLeftValue(root: TreeNode): Int = {
    var r = root
    val q = new mutable.Queue[TreeNode]()
    q.enqueue(r)
    while (q.nonEmpty) {
      r = q.front
      q.dequeue
      if (r.right != null) q.enqueue(r.right)
      if (r.left != null) q.enqueue(r.left)
    }
    r.value
  }
}
```
