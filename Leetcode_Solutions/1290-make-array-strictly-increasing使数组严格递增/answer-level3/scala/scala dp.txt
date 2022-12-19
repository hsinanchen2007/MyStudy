```scala
object Solution {
  def makeArrayIncreasing(arr1: Array[Int], arr2: Array[Int]): Int = {
    val res = -1
    if (arr1 == null || arr2 == null || arr1.length == 0 || arr2.length == 0) return res
    val dp = Array.fill(arr1.length + 1, arr1.length + 1)(Int.MaxValue)
    dp(0)(0) = -1
    val array2 = arr2.sorted
    (1 to arr1.length).foreach(i => {
      val index = i - 1
      (0 to i).foreach(j => {
        if (arr1(index) > dp(j)(i - 1)) dp(j)(i) = arr1(index)
        if (j > 0) {
          val tmp = upperBound(array2, 0, array2.length - 1, dp(j - 1)(i - 1))
          dp(j)(i) = dp(j)(i).min(tmp)
        }
        if (i == arr1.length && dp(j)(i) != Int.MaxValue) return j
      })
    })
    -1
  }

  def upperBound(array: Array[Int], l: Int, r: Int, key: Int): Int = {
    var left = l
    var right = r
    while (left <= right) {
      val mid = (left + right) / 2
      if (array(mid) <= key) left = mid + 1 else right = mid - 1
    }
    if (left >= array.length || array(left) <= key) return Int.MaxValue
    array(left)
  }
}
```
