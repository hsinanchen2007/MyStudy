### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def findUnsortedSubarray(nums: Array[Int]): Int = {
  import java.util
    val snums = nums.clone()
    util.Arrays.sort(snums)
    var start = snums.length
    var end = 0
    for (i <- snums.indices) {
      if (snums(i) != nums(i)) {
        start = Math.min(start, i)
        end = Math.max(end, i)
      }
    }
    if (end - start >= 0)
      return end - start + 1
    0
    }
}
```