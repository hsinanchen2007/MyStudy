```scala
object Solution {
  def minDiffInBST(root: TreeNode): Int = {
    var v = Set[Int]()

    def func(root: TreeNode): Unit = root match {
      case null =>
      case _ =>
        v += root.value
        func(root.left)
        func(root.right)
    }

    func(root)
    val values = v.toList.sorted
    (values zip values.tail).map(x => x._2 - x._1).min
  }
}
```
