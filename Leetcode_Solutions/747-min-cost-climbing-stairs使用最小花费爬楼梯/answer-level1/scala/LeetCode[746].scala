```
object Solution {
  def minCostClimbingStairs(cost: Array[Int]): Int = {
    val ret = new Array[Int](cost.length)
    ret(0) = cost(0)
    ret(1) = cost(1)
    for(i <-2 to cost.size-1){
      ret(i) = cost(i) + math.min(ret(i-1),ret(i-2))
    }
    math.min(ret(cost.length-1), ret(cost.length-2))
  }
}
```
