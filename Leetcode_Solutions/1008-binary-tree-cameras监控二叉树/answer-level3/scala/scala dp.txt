```scala
object Solution {
  def minCameraCover(root: TreeNode): Int = dp(root).tail.min

  def dp(root: TreeNode): List[Int] = root match {
    case null => List(0, 0, 1e9.toInt)
    case _ =>
      val l = dp(root.left)
      val r = dp(root.right)
      (l(1) + r(1)) :: (l(2) + r.tail.min).min(r(2) + l.tail.min) :: (1 + l.min + r.min) :: Nil
  }
}
```