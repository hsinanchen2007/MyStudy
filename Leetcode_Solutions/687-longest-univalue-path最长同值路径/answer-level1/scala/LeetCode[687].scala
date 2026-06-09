# 最长同值路径

对于一棵树而言， 最长同值路径可能存在如下可能

**1. 路径经过根节点
2. 不经过根节点存在左子树中， 长度为longestUnivaluePath(root.left)
3. 不经过根节点存在右子树中， 长度为longestUnivaluePath(root.right)**

至此问题可以拆解为 求路径经过根节点的问题， 具体的逻辑见dfs函数。大意是经过根节点的路径和等于该节点在两个子书的深度之和（前提是左右子树的根节点和根节点相同， 否则置0）

```
object Solution {
  def dfs(root: TreeNode): (Int, Int) = {
    if (root == null) return (0, 0)
    val left = dfs(root.left)
    val right = dfs(root.right)
    val a = if (root.left != null && root.left.value == root.value) left._2 + 1 else 0
    val b = if (root.right != null && root.right.value == root.value) right._2 + 1 else 0
    (a + b, math.max(a, b))
  }

  def longestUnivaluePath(root: TreeNode): Int = {
    if (root == null) return 0
    List(dfs(root)._1, longestUnivaluePath(root.left), longestUnivaluePath(root.right)).max
  }
}

```
