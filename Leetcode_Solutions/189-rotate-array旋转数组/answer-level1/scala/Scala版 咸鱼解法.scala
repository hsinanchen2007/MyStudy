```Scala
object Solution {
    def rotate(nums: Array[Int], k: Int): Unit = {
    if (k == 0) println(nums)
    else {
      for (_ <- 1 to (k % nums.length)) {
        val tmp = nums(nums.length - 1)
        for (j <- (0 to nums.length - 2).reverse)
          nums(j + 1) = nums(j)
        nums(0) = tmp
      }
    }
  }
}
```
