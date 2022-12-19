### 解题思路
简单

### 代码

```scala
object Solution {
    def numJewelsInStones(J: String, S: String): Int = {
       var count = 0
      for (i <- 0 until S.length) {
        if (J.contains(S(i))) {
          count += 1
        }
      }
      count
    }
}
```