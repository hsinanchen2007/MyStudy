```
object Solution {
  def matrixReshape(nums: Array[Array[Int]], r: Int, c: Int): Array[Array[Int]] = {
    val rr = nums.length
    val cc = nums(0).length
    if (rr * cc != r * c) return nums
    val ret = Array.ofDim[Int](r, c)

    for(i <- 0 until r){
      for(j <- 0 until c){
        val index = i * c + j 
        val indexC = index % cc
        val indexR = index / cc
        ret(i)(j) = nums(indexR)(indexC)
      }
    }
    return ret
  }
}
```
