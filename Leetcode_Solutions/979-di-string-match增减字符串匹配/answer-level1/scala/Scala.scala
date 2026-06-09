### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def diStringMatch(S: String): Array[Int] = {
    val N = S.length
    var lo = 0
    var hi = N
    val ans = new Array[Int](N + 1)

    for (i <-0 until N) {
      if (S.charAt(i) == 'I') {
        ans(i) = lo
        lo += 1
      } else {
        ans(i) = hi
        hi -= 1
      }

      ans(N) = lo
    }
    ans    
    }
}
```