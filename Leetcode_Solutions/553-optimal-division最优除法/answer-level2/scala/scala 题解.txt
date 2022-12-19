```scala
object Solution {
  def optimalDivision(nums: Array[Int]): String = nums.toList match {
    case h :: Nil => h.toString
    case x :: y :: Nil => x + "/" + y
    case h :: t => h + "/(" + t.mkString("/") + ")"
  }
}
```
