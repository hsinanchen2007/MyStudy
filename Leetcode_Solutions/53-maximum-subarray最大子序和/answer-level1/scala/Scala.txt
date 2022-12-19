### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def maxSubArray(nums: Array[Int]): Int = {
     var max_sum = nums(0)
    for (i <- 1 until nums.length ) {
      if (nums(i - 1) > 0) {
        nums(i) += nums(i - 1)
      }
      max_sum = math.max(nums(i), max_sum)
    }
    max_sum   
    }
}
```