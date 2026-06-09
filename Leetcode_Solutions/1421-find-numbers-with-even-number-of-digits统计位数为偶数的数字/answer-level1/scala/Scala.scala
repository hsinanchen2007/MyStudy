### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def findNumbers(nums: Array[Int]): Int = {
      var count = 0
    for (i <- nums.indices) {
      if (nums(i).toString.length % 2 == 0)
        count += 1
    }
    count  
    }
}
```