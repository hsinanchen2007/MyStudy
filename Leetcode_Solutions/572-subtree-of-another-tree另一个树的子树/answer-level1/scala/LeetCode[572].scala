```
object Solution {

  //def eqTree(s: TreeNode, t: TreeNode): Boolean = {
  //if( s == null && t == null ) return true
  //if( s == null || t == null ) return false
  //if( s.value != t.value ) return false
  //eqTree(s.left, t.left) && eqTree(s.right, t.right)
  //}

  //def isSubtree(s: TreeNode, t: TreeNode): Boolean = {
  //if(s == null) return false
  //if(eqTree(s,t)) return true
  //return isSubtree(s.left, t) || isSubtree(s.right, t)
  //}
  def preOrder(root: TreeNode): String = {
    if (root == null) return "null"
    "#" + root.value.toString + preOrder(root.left) + preOrder(root.right)
  }

  def isSubtree(s: TreeNode, t: TreeNode): Boolean = {
    val s1 = preOrder(s)
    val s2 = preOrder(t)
    s1.contains(s2)
  }
}
```
