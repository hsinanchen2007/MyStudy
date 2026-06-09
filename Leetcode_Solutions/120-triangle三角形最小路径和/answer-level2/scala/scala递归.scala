```
  @scala.annotation.tailrec
  def minimumTotal(triangle: List[List[Int]]): Int = triangle match {
    case first :: Nil => first.min
    case first :: second :: rest =>
      val newHead = second.zipWithIndex.map { case (num, index) =>
        val left = first((index - 1).max(0))
        val right = first(index.min(first.length - 1))
        num + left.min(right)
      }
      minimumTotal(newHead +: rest)
}
```
