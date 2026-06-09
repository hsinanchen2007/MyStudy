### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def findLHS(nums: Array[Int]): Int = {
     val num = nums.sorted
    var begin = 0
    var res = 0
    for (i <- num.indices) {
      while (num(i) - num(begin) > 1)
        begin += 1
      if (num(i) - num(begin) == 1)
        res = Math.max(res, i - begin + 1)
    }
    res   
    }
}
```