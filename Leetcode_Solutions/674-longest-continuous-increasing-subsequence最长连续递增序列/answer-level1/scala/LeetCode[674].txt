```
object Solution {
  def findLengthOfLCIS(nums: Array[Int]): Int = {
    if (nums.length == 0) return 0
    var num = 1
    var max_num = Int.MinValue
    var i = 0

    while (i <= nums.length - 1) {
      var j = i + 1
      import util.control.Breaks._
      breakable {
        while (j < nums.length) {
          if (nums(j) > nums(j - 1)) {
            num += 1
            j += 1
          }
          else {
            max_num = math.max(max_num, num)
            num = 1
            break
          }
        }
      }
      i = j
    }

    return math.max(num, max_num)
  }
}

```
