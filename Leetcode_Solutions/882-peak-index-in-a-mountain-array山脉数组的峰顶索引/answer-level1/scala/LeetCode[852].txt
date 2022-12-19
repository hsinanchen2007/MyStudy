```
object Solution {
  def peakIndexInMountainArray(A: Array[Int]): Int = {
    for (i <- 1 to A.length - 2) {
      if (A(i) > A(i - 1) && A(i) > A(i + 1)) return i
    }
    return -1
  }
}
```


```
object Solution {
  def peakIndexInMountainArray(A: Array[Int]): Int = {
    var left = 0
    var right = A.length - 1
    while (left < right) {
      val mid: Int = (left + right) >> 1
      if (A(mid) > A(mid - 1) && A(mid) > A(mid + 1)) return mid
      else if (A(mid) < A(mid - 1)) {
        right = mid
      } else if (A(mid) < A(mid + 1)) {
        left = mid + 1
      }
    }
    return -1
  }
}
```