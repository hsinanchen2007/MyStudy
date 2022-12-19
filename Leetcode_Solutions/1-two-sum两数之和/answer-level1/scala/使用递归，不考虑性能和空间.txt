### 解题思路
使用递归，不考虑性能和空间

### 代码

```scala
object Solution {
    //@scala.annotation.tailrec
    def func(numsIdx: Array[(Int, Int)], target: Int): Array[Int] = {
        val expect = target - numsIdx.head._1
        for (i <- numsIdx.tail) {
            //System.out.println(expect + ", " + i.toString)
            if (i._1 == expect) {
                return Array(numsIdx.head._2, i._2)
            }
        }
        return func(numsIdx.tail, target)
    }
    def twoSum(nums: Array[Int], target: Int): Array[Int] = {
        func(nums.zipWithIndex, target)
    }
}
```