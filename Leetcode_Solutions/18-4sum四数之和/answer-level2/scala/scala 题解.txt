```scala
object Solution {
  def fourSum(nums: Array[Int], target: Int): List[List[Int]] = {
    solve(nums.sorted, target)
  }

  def solve(nums: Array[Int], target: Int): List[List[Int]] = {
    nums.indices.flatMap(i =>
      f(i + 1, nums, target - nums(i)) match {
        case Nil => Nil
        case l => l.map(li => nums(i) :: li)
      }).filter(_.nonEmpty).toList.distinct
  }

  def f(i: Int, nums: Array[Int], target: Int): List[List[Int]] = {
    (i until nums.length).flatMap(i =>
      g(i + 1, nums, target - nums(i)) match {
        case l => for (li <- l) yield nums(i) :: li
      }).filter(_.nonEmpty).toList
  }

  def g(i: Int, nums: Array[Int], target: Int): List[List[Int]] = {
    (i until nums.length).flatMap(x =>
      (x + 1 until nums.length).withFilter(y =>
        nums(x) + nums(y) == target).map(y =>
        List(nums(x), nums(y)))).filter(_.nonEmpty).toList
  }

  def k(nums: Array[Int], target: Int): List[List[Int]] = {
    nums.indices.flatMap(i =>
      (i + 1 until nums.length).flatMap(j =>
        (j + 1 until nums.length).flatMap(k =>
          (k + 1 until nums.length).withFilter(l =>
            nums(i) + nums(j) + nums(k) + nums(l) == target).map(l =>
            List(nums(i), nums(j), nums(k), nums(l)))
        )
      )
    ).toSet.toList
  }
}
```
