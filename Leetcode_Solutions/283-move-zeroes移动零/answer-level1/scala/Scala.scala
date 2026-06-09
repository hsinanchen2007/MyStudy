### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def moveZeroes(nums: Array[Int]): Unit = {
    val l = nums.length
    var index = 0
    for (i <- 0 until l) {
      if (nums(i) != 0) {
        nums(index) = nums(i)
        if (index != i) {
          nums(i) = 0
        }
        index += 1
    }
    }
    }
}
```