```
object Solution {
  def checkPossibility(nums: Array[Int]): Boolean = {
    if (nums.length <= 2) return true
    import util.control.Breaks._
    var num = 0 
    breakable {
      for (i <- 1 until nums.length) {
        if (nums(i) < nums(i-1)) {
          if(i == 1) {
            nums(i-1) = nums(i)
          } else if ( i == nums.size - 1 ) {
            nums(i) = nums(i - 1)
          } else {
            if(nums(i) < nums(i-2)) {
              nums(i) = nums(i-1)
            } else {
              nums(i-1) = nums(i)
            }
          }
          break
        }

      }

    }
    for (i <- 1 to nums.length - 1) {
      if (nums(i) < nums(i - 1)) return false
    }
    return true
  }
}

```
