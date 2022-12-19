### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def findErrorNums(nums: Array[Int]): Array[Int] = {
    val counter: Array[Int] = new Array[Int](nums.length + 1)
    for (i <- nums) {
      counter(i) += 1
    }
    val result: Array[Int] = new Array[Int](2)
    for (i <- 1 until counter.length) {
      if (counter(i) == 0) {
        result(1) = i
      }
      else {
        if (counter(i) == 2) {
          result(0) = i
        }
      }
    }
    result    
    }
}
```