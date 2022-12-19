### 解题思路

大致思路就是数字转成byte数组，比较数组中的数字大小，符合规则的调换位置，双层遍历， 第一层自左向右，第二层自右侧向左

### 代码

```scala
object Solution {
    def maximumSwap(num: Int): Int = {
    var cha = num.toString.getBytes
    for (i <- 0 until cha.size) {
      var fag = false
      if (i + 1 < cha.size) {
        var nx = 0
         var inx ="0".toByte
        for (j <- (i + 1 until cha.size).reverse) {
          val b1: Byte = cha(j)
          if (cha(j) > cha(i).toInt)
            if (cha(j).toInt > inx.toInt) {
              inx = cha(j)
              nx = j
              fag = true
            }
          if (j == i + 1 && fag) {
            cha(nx) = cha(i)
            cha(i) = inx
            return new String(cha).toInt
          }

        }
      }
    }
    num
  }
    
}