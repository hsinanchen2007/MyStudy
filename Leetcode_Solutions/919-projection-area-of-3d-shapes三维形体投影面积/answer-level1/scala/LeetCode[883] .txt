```
object Solution {
  def projectionArea(grid: Array[Array[Int]]): Int = {
    grid.flatten.count(_ != 0) + grid.map(_.max).sum + grid.transpose.map(_.max).sum
  }
}
```


xy 平面上的面积 取决于输入的矩阵中有多少个0【这部分面积要被挖掉】。
xz 平面上的面积 取决于每一行（假设x是行，y是列）的最大值。
yz 平面上的面积同上， 转置矩阵即可。