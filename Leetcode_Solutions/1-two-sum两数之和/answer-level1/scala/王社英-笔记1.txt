
1,第一个算法,肯定是最基础,也是最容易实现的算法,暴力穷举
```
object Solution {
  def twoSum(nums: Array[Int], target: Int): Array[Int] = {
    val index = new Array[Int](2)
    val len = nums.indices
    for (x <- len; y <- len; if x != y; if target == nums(x) + nums(y)) {
      index(0) = x
      index(1) = y
      return index
    }
    return index
  }
}
```

2,第二个算法,开始高级一点了,利用hash实现
```

object Solution {
  def twoSum(nums: Array[Int], target: Int): Array[Int] = {
    val index = new Array[Int](2)
    val a = nums.zipWithIndex.toMap
    for (x <- nums; y = target - x; if a.contains(y) && x != y) {
      index(0) = a(x)
      index(1) = a(y)
      return index
    }
    var count = 0
    for (i <- nums.indices; if nums(i) == target / 2) {
      index(count) = i
      count += 1
    }
    return index
  }
}

```
两个数的和等于target,那么这两个数,要么相等,要么不相等
1. 如果不相等,直接可以通过差的hash值找到
2. 否则相等的话,必然等于target/2,直接遍历数组,找到下标即可

3,优化一下,解法2,不用直接把所有都存到map,但看结果,对计算效率没啥提升
```
object Solution {
  def twoSum(nums: Array[Int], target: Int): Array[Int] = {
    val index = new Array[Int](2)
    import scala.collection.mutable
    val a = mutable.HashMap[Int, Int]()
    for ((x, i) <- nums.zipWithIndex; y = target - x) {
      if (a.contains(y) && x != y) {
        index(0) = a(x)
        index(1) = a(y)
        return index
      } else {
        a += (x -> i)
      }
    }
    var count = 0
    for (i <- nums.indices; if nums(i) == target / 2) {
      index(count) = i
      count += 1
    }
    return index
  }
}
```

