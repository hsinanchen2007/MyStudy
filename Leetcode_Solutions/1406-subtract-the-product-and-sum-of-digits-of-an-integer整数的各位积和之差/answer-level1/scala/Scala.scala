### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def subtractProductAndSum(n: Int): Int = {
    import scala.collection.mutable.ListBuffer
    val A = new ListBuffer[Int]
    val m = n.toString
    for (i <- m) {
      A += i.toString.toInt
    }
    val s = A.reduce(sum)
    val ml = A.reduce(multiple)
    ml - s
  }
  def sum(n1: Int, n2: Int): Int = {
    n1 + n2
  }
  def multiple(n1: Int, n2: Int): Int = {
    n1 * n2
  }    
    
}
```