最大元素至少是数组中每个其他数字的两倍也即最大元素是次大元素的两倍

```scala
object Solution {
    def dominantIndex(nums: Array[Int]): Int = {
        if(nums.size < 2) {
            0
        } else {
            val sortedNums = nums.indices.map {case i => (nums(i), i)} sortWith(_._1 < _._1)
            val lastTwo = sortedNums(sortedNums.size-2)._1
            if ((sortedNums.last._1 - lastTwo) >= lastTwo) {
                sortedNums.last._2
            } else {
                -1
            }
        }
    }
}
```

数组少于两个元素时直接返回0，多于2个元素时先进行排序，这里将元素在原数组中的位置保存了下来，方便直接返回。