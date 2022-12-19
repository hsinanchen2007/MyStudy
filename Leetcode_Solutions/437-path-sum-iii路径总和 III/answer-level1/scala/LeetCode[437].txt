```
object Solution {
  def pathSum(root: TreeNode, sum: Int): Int = {
    if (root == null) return 0
    if (root.left == null && root.right == null) if (root.value == sum) return 1 else 0
    import scala.collection.mutable.Stack
    val mystack = new Stack[(TreeNode, List[Int])]()
    mystack.push((root, List(root.value)))

    var num = 0
    while (mystack.nonEmpty) {
      val (node, sumpath) = mystack.pop
      num += sumpath.count((_: Int) == sum)
      if (node.left != null) {
        mystack.push((node.left, node.left.value :: sumpath.map(x => x + node.left.value)))
      }
      if (node.right != null) {
        mystack.push((node.right, node.right.value :: sumpath.map(x => x + node.right.value)))
      }
    }
    return num
  }
}

```
