```scala
object Solution {
  def nextGreaterElements(nums: Array[Int]): Array[Int] = {
    val st = new mutable.Stack[Int]
    val res = new Array[Int](nums.length)
    res.indices.foreach(i => res(i) = -1)
    (0 until 2 * nums.length).foreach(i => {
      val num = nums(i % nums.length)
      while (st.nonEmpty && nums(st.top) < num) {
        res(st.top) = num
        st.pop
      }
      if (i < nums.length) st.push(i)
    })
    res
  }
}
```
