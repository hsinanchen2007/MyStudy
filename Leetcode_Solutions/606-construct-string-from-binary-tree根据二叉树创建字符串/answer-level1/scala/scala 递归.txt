```scala
object Solution {
  def tree2str(t: TreeNode): String = {
    if (t == null) return ""
    var res = t.value.toString
    if (t.left == null && t.right == null) return res
    res += "(" + tree2str(t.left) + ")"
    if (t.right != null) res += "(" + tree2str(t.right) + ")"
    res
  }
}
```
