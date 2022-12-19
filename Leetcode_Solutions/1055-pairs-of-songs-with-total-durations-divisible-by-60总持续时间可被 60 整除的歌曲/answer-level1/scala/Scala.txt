### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def numPairsDivisibleBy60(time: Array[Int]): Int = {
    var i = 0
    var count = 0
    while (i < time.length) {
      for (j <- (i + 1) until time.length) {
        if ((time(i) + time(j)) % 60 == 0)
          count += 1
      }
      i += 1
    }
    count    
    }
}
```