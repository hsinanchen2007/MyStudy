### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def replaceElements(arr: Array[Int]): Array[Int] = {
    var max = -1
    for (i <- arr.length - 1 to 0 by -1) {
      val temp = arr(i)
      arr(i) = max
      if (temp > max) max = temp
    }
    arr  
    }
}
```