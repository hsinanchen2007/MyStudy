```
object Solution {
  var preSum = 0

  def dfs(root: TreeNode): Unit = {
    if (root == null) return
    dfs(root.right)
    val tmp = root.value
    root.value += preSum
    preSum += tmp
    dfs(root.left)
  }

  def convertBST(root: TreeNode): TreeNode = {
    preSum = 0
    dfs(root)
    return root
  }
}
```
