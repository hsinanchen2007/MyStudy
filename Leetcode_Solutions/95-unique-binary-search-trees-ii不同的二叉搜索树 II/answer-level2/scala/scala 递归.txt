```scala
object Solution {
  def generateTrees(n: Int): List[TreeNode] = n match {
    case 0 => List()
    case _ => func(1, n)
  }

  def func(start: Int, end: Int): List[TreeNode] = {
    if (start > end) return List(null)
    var res = List[TreeNode]()
    (start to end).foreach(i => {
      val left = func(start, i - 1)
      val right = func(i + 1, end)
      left.foreach(j => right.foreach(k => {
        var node = new TreeNode(i)
        node.left = j
        node.right = k
        res ::= node
      }))
    })
    res
  }
}
```
