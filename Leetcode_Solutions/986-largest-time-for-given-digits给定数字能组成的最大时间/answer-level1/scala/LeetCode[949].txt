```
object Solution {
  def largestTimeFromDigits(A: Array[Int]): String = {
    val list: List[Array[Int]] = A.permutations.toList
    val filter = list.filter(x => x(0) * 10 + x(1) <= 23 && x(2) * 10 + x(3) <= 59)
    if (filter.isEmpty) return ""
    val ints: Array[Int] = filter.maxBy(x => {
      (x(0) * 10 + x(1)) * 60 + x(2) * 10 + x(3)
    })
    ints(0).toString + ints(1).toString + ":" + ints(2).toString + ints(3).toString
  }
}
```
