### 解题思路
求中位数；有点像中庸思想，解决群组性差异时，走中位数路线最稳妥，因为整体要做的改变最少。注意，中位数不是平均值，不会有一个个体有超大的差异，结果其他人都要将就他；中位数情况下，那个差异最大的个体，要移动必然是最多的，且比移动到平均值要更费力气
刚开始第17个案例挂了，因为没有考虑到Int类型容纳不下，溢出。改为BigInt解决

### 代码

```scala
object Solution {
    def minMoves2(nums: Array[Int]): Int = {
        //生成2个数组，一个正序，一个逆序；然后一个zip操作，将其拉成2个元组，求元组两数差异绝对值，求和除2
        val x = nums.sorted
        val y = x.reverse
        val z = x.zip(y)
        var res:BigInt = 0
        z.foreach(tu => res += Math.abs(tu._1-tu._2 ))
        (res/2).toInt
    }
}
```