### 解题思路
此处撰写解题思路

### 代码
```scala
object Solution {
    def trailingZeroes(n: Int): Int = {
         var i: Int = n
    var count = 0
    while (i > 0) {
      count += i / 5
      i = i / 5
    }
    count
    }
}
```