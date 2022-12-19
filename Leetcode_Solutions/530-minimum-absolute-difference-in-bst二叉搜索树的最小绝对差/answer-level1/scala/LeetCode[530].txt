**中序遍历BST可以形成递增序列， 由于最小间距一定是相邻节点之间产生， 因此可以声明pre节点，借助数组或者队列等空间来存储整个树**

```
object Solution {
  var pre: TreeNode = null
  var min: Int = Int.MaxValue

  def inOrder(root: TreeNode): Int = {
    if (root == null) return Int.MaxValue
    val left_value: Int = inOrder(root.left)
    val root_value: Int = if (pre == null) Int.MaxValue
    else math.abs(root.value - pre.value)
    pre = root
    val right_value: Int = inOrder(root.right)
    List(left_value, root_value, right_value).min
  }

  def getMinimumDifference(root: TreeNode): Int = {
    inOrder(root)
  }
```
