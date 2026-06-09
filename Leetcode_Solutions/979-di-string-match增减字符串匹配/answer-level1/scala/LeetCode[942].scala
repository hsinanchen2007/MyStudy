```
object Solution {
  def diStringMatch(S: String): Array[Int] = {
    val arr = new Array[Int](S.length + 1)
    var left = 0
    var right = arr.length - 1

    for (i <- 0 to S.length - 1) {
      if (S(i) == 'I') {
        arr(i) = left
        left += 1
      }
      else {
        arr(i) = right
        right -= 1
      }
    }
    arr(arr.length -1) = left
    return arr
  }
}
```
