### 解题思路
二维求最小距离，分解成x轴上和y轴上求最小距离（Leetcode462里面算法）
曼哈顿距离的特点是x轴和y轴距离是可以分开计算然后合起来
### 代码

```scala
object Solution {
    def minTotalDistance(grid: Array[Array[Int]]): Int = {
        //分治思想，这是二维求最小距离，分解成x轴上和y轴上求最小距离；
        //某个轴上是一维求最小距离，正好可以用Leetcode462里面算法；见子函数
        val x = scala.collection.mutable.ArrayBuffer[Int]()
        val y = scala.collection.mutable.ArrayBuffer[Int]()
        for (i <- 0 until grid.length; j <- 0 until grid(i).length)  {
            if (grid(i)(j) == 1) {
                x += i
                y += j
            }
        }
        var res = 0
        res += minMoves2(x.toArray)
        res += minMoves2(y.toArray)
        res
    }
    def minMoves2(nums: Array[Int]): Int = {
        //子函数：求一维上最小移动距离，采用中位数算法
        //方法：生成2个tmp数组，一个正序，一个逆序；然后一个zip操作，将其拉成二元组，求元组两数差异绝对值，求和除2
        val x = nums.sorted
        val y = x.reverse
        val z = x.zip(y)
        var res:BigInt = 0
        z.foreach(tu => res += Math.abs(tu._1-tu._2 ))
        (res/2).toInt
    }
}
```