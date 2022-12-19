### 解题思路

由于缺少一个元素，且数组有序，设数组长度为`len`，那么在`[0,len]`这个闭区间所有元素的和减去nums中所有元素的和就是缺失的元素。

### 代码

```scala
object Solution {
    def missingNumber(nums: Array[Int]): Int = {
        (0 to nums.length).toList.foldLeft(0)(_ + _) - nums.foldLeft(0)(_ + _)
    }
}
```