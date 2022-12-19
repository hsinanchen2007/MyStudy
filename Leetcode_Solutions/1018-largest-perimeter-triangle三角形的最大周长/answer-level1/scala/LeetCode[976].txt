```
object Solution {
  def largestPerimeter(A: Array[Int]): Int = {
    if (A.length < 3) return 0
    val sort = A.sorted.reverse
    for (i <- 0 to sort.length - 3) {
      if (sort(i) < sort(i + 1) + sort(i + 2))
        return (sort(i) + sort(i + 1) + sort(i + 2))
    }
    return 0
  }
}

```
