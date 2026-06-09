### 解题思路
此处撰写解题思路
从起点为(i,j)开始，先判断本节点是否可以，如果不可以就终止，如果可以，分别判断右侧和下侧即可，不用判断左侧和上侧，因为本节点一定是由左侧或者上侧的节点过来的；使用一个exist[m][n]分别记录访问过的节点是否符合要求,
于是结果就是 result = count(0,0) = if(符合条件){1 + count(右侧) + count(下侧)} else 0 这样一个回溯计算

### 代码

```scala
object Solution {
  def movingCount(m: Int, n: Int, k: Int): Int = {
    if(m <= 0 || n <= 0) return 0
    val exist = Array.ofDim[Int](m, n)
    def move(i:Int, j:Int): Int = {
      var count = 0
      if(i < m && j < n && exist(i)(j) != 1 && (getNumSum(i) + getNumSum(j)) <= k) {
        exist(i)(j) = 1
        count = 1 + move(i + 1, j) + move(i, j + 1)
      }
      count
    }
    def getNumSum(n: Int) : Int = {
      var sum = 0
      var t = n
      while(t > 0) {
        sum += t % 10
        t /= 10
      }
      sum
    }
    move(0,0)
  }
}
```