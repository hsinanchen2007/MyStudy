object Solution {
    def searchInsert(nums: Array[Int], target: Int): Int = {
    var res = 0
    if (target > nums.max)
      return nums.length
    if (target < nums.min)
      return 0
    for (i <- nums.indices) {
      if (nums(i) == target)
        res = i
      if (target > nums(i) && target < nums(i + 1)) {
        res = i + 1
      }
    }
    res
    }
}