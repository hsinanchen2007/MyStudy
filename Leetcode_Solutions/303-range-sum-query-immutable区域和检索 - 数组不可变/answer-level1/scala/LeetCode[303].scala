```
class NumArray(_nums: Array[Int]) {
  val sum = new Array[Int](_nums.size)
  for (i <- 0 until _nums.size; j <- 0 to i) {
    sum(i) += _nums(j)
  }

  def sumRange(i: Int, j: Int): Int = {
    //sumRange[i,j] = sum(j) - sum(i) + _nums(i)
    sum(j) - sum(i) + _nums(i)
  }

}
```
