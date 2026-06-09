```
object Solution {
  def func(root: TreeNode, sum: Int, preSum: Int, mymap: scala.collection.mutable.Map[Int, Int]): Int = {
    var num = 0
    if (root == null) return 0
    val newPreSum: Int = root.value + preSum
    if (mymap.contains(newPreSum - sum)) {
      num += mymap(newPreSum - sum)
    }
    if (mymap.contains(newPreSum)) mymap(newPreSum) += 1
    else mymap(newPreSum) = 1
    num += func(root.left, sum, newPreSum, mymap)
    num += func(root.right, sum, newPreSum, mymap)
    if (mymap(newPreSum) == 1) mymap.remove(newPreSum)
    else mymap(newPreSum) -= 1
    return num
  }

  def pathSum(root: TreeNode, sum: Int): Int = {
    var preSum = 0
    val mymap = scala.collection.mutable.Map[Int, Int]()
    mymap(0) = 1
    func(root, sum, preSum, mymap)
  }
}
```
