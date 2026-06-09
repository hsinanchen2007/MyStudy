### 解题思路
先把Array排序就只用比较相邻的元素了

### 代码

```scala
object Solution {
    def containsDuplicate(nums: Array[Int]): Boolean = {
            var i = 0
    val num = nums.sorted
    if (num.length == 0) return false
    while (i < num.length - 1)
      if (num(i) == num(i + 1)) {
        return true
      } else {
        i += 1
      }
    false
    }
}
```