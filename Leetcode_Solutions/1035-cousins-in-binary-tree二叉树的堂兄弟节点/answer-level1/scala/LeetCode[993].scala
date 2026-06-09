```
object Solution {
  def existsCouson(nodes: List[(TreeNode, TreeNode)], x: Int, y: Int): Boolean = {
    val xNode: Option[(TreeNode, TreeNode)] = nodes.find(item => item._2.value == x)
    val yNode: Option[(TreeNode, TreeNode)] = nodes.find(item => item._2.value == y)
    if (xNode.isDefined && yNode.isDefined && xNode.get._1 != yNode.get._1) return true
    else false
  }

  def isCousins(root: TreeNode, x: Int, y: Int): Boolean = {
    import scala.collection.mutable.Queue
    val myqueue = new Queue[(TreeNode, TreeNode)]()
    if (root == null) return false
    myqueue.enqueue((null, root))
    while (myqueue.nonEmpty) {
      val roots = myqueue.dequeueAll(_ => true)
      if (existsCouson(roots.toList, x, y)) return true
      for (elem <- roots) {
        if(elem._2.left != null) myqueue.enqueue((elem._2, elem._2.left))
        if(elem._2.right!= null) myqueue.enqueue((elem._2, elem._2.right))
      }
    }
    return false
  }
}

```
