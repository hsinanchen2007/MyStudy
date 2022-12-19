```
object Solution {

  def dfs(root: TreeNode, L: Int, R: Int): Int = {
    var sum = 0
    if (root == null) return 0
    if (root.value <= R && root.value >= L) {
      sum += root.value
    }
    sum += dfs(root.left, L, R)
    sum += dfs(root.right, L, R)
    return sum
  }

  def rangeSumBST(root: TreeNode, L: Int, R: Int): Int = {
    dfs(root, L, R)
  }
}
```
