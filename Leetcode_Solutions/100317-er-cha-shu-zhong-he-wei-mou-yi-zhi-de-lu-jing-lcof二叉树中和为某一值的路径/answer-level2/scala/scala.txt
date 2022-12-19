```scala
/**
 * Definition for a binary tree node.
 * class TreeNode(var _value: Int) {
 *   var value: Int = _value
 *   var left: TreeNode = null
 *   var right: TreeNode = null
 * }
 */
object Solution {
  def pathSum(root: TreeNode, target: Int): List[List[Int]] = {

    def func(root: TreeNode): List[(Int, List[Int])] = {
      if (root == null) List.empty
      else if (root.left == null && root.right == null) List((root.value, List(root.value)))
      else {
        val l = func(root.left)
        val r = func(root.right)
        l.map { case (sum, path) => (sum + root.value, root.value :: path) } :::
          r.map { case (sum, path) => (sum + root.value, root.value :: path) }
      }
    }

    func(root).withFilter({ case (sum, _) => sum == target }).map({ case (_, path) => path })
  }
}
```