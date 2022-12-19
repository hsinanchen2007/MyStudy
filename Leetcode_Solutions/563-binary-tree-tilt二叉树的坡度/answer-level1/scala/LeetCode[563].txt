```
object Solution {
  def sum(root:TreeNode): Int = {
    if(root == null) return 0 
    else root.value + sum(root.left) + sum(root.right)
  }
  def findTilt(root: TreeNode): Int = {
    if(root==null) return 0
    findTilt(root.left) + findTilt(root.right) + math.abs(sum(root.left) - sum(root.right))
  } 
}
```
