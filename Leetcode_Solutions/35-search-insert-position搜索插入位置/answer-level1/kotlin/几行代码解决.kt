先判断清楚两种情况 找到和找不到, 找到就返回当前下标
找不到又分最小, 最大, 和中间
三种找不到其实可以套用一种模式, 就是先默认最小,var point = 0
如果当前遍历的元素比target大, 那就不改动
如果比target小, 那就说明target一定至少是它的下一位, 所以point在当前元素的引索值上加1
若一直没有找到目标, 循环结束返回point, 这就是最终target归属的位置
```kotlin
fun searchInsert(nums: IntArray, target: Int): Int {
    var point = 0
    for (i in nums) {
        if (i == target) return point
        else if (target > i) {
            point = nums.indexOf(i) + 1
        }
    }
    return point
}
```
