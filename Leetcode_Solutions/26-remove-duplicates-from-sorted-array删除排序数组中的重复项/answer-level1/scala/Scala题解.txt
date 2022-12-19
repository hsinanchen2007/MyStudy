object Solution {
    def removeDuplicates(nums: Array[Int]): Int = {
    var i = 0
    if (nums.length == 0) return 0
    for (j <- 1 until nums.length) {
      if (nums(j) != nums(i)) {
        i += 1
        nums(i) = nums(j)
      }
    }
    i + 1
    }
}