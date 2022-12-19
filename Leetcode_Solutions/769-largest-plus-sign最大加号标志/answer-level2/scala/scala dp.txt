![4U@GC5RI_LDF4M$2PWFUD}2.png](https://pic.leetcode-cn.com/a6f9f57ef0355cca43ac1f154aa1d8c6a55d0ee0a90080e172affc03fdf9f9a0-4U@GC5RI_LDF4M$2PWFUD%7D2.png)
**方法1**
```scala
import scala.collection.mutable

object Solution {
  def orderOfLargestPlusSign(N: Int, mines: Array[Array[Int]]): Int = {
    var res = 0
    var cnt = 0
    val dp = Array.ofDim[Int](N, N)
    val s = new mutable.HashSet[Int]()
    mines.foreach(i => s.add(i(0) * N + i(1)))
    (0 until N).foreach(i => {
      cnt = 0
      (0 until N).foreach(j => {
        cnt = if (s.contains(j * N + i)) 0 else cnt + 1
        dp(j)(i) = cnt
      })
      cnt = 0
      (N - 1 to 0 by -1).foreach(j => {
        cnt = if (s.contains(j * N + i)) 0 else cnt + 1
        dp(j)(i) = dp(j)(i).min(cnt)
      })
    })
    (0 until N).foreach(i => {
      cnt = 0
      (0 until N).foreach(j => {
        cnt = if (s.contains(i * N + j)) 0 else cnt + 1
        dp(i)(j) = dp(i)(j).min(cnt)
      })
      cnt = 0
      (N - 1 to 0 by -1).foreach(j => {
        cnt = if (s.contains(i * N + j)) 0 else cnt + 1
        dp(i)(j) = dp(i)(j).min(cnt)
        res = res.max(dp(i)(j))
      })
    })
    res
  }
}
```
**方法2**
```scala
object Solution {
  def orderOfLargestPlusSign(N: Int, mines: Array[Array[Int]]): Int = {
    var res = 0
    val dp = Array.fill(N, N)(N)
    mines.foreach(i => dp(i(0))(i(1)) = 0)
    (0 until N).foreach(i => {
      var left = 0
      var right = 0
      var up = 0
      var down = 0

      var j = 0
      var k = N - 1
      while (j < N) {
        left = if (dp(i)(j) > 0) left + 1 else 0
        dp(i)(j) = dp(i)(j).min(left)
        up = if (dp(j)(i) > 0) up + 1 else 0
        dp(j)(i) = dp(j)(i).min(up)
        right = if (dp(i)(k) > 0) right + 1 else 0
        dp(i)(k) = dp(i)(k).min(right)
        down = if (dp(k)(i) > 0) down + 1 else 0
        dp(k)(i) = dp(k)(i).min(down)
        j += 1
        k -= 1
      }
    })
    (0 until N * N).foreach(i => res = res.max(dp(i / N)(i % N)))
    res
  }
}
```
**方法3**
```
object Solution {
  def orderOfLargestPlusSign(N: Int, mines: Array[Array[Int]]): Int = {
    var res = 0
    val arr = Array.fill(N, N)(1)
    mines.foreach(i => arr(i(0))(i(1)) = 0)
    (0 until N).foreach(i => (0 until N).foreach(j => {
      var t = 0
      while (func(arr, N, i, j, t)) t += 1
      res = res.max(t)
    }))
    res
  }

  def func(arr: Array[Array[Int]], N: Int, x: Int, y: Int, k: Int): Boolean = {
    if (x - k < 0 || y - k < 0 || x + k >= N || y + k >= N) false
    else arr(x - k)(y) > 0 && arr(x)(y + k) > 0 && arr(x + k)(y) > 0 && arr(x)(y - k) > 0
  }
}
```
