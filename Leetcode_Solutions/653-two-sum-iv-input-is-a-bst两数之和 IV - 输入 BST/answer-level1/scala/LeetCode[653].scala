```
object Solution {
  def dfs(root: TreeNode, arr: scala.collection.mutable.ArrayBuffer[Int], k: Int): Boolean = {
    if (root == null) return false
    val leftFlag = dfs(root.left, arr, k)
    if (arr.contains(k - root.value)) return true
    else {
      arr += root.value
    }
    val rightFlag = dfs(root.right, arr, k)
    return leftFlag || rightFlag
  }

  def findTarget(root: TreeNode, k: Int): Boolean = {
    if (root == null) return false
    import scala.collection.mutable.ArrayBuffer
    val myArrayBuffer = new ArrayBuffer[Int]()
    dfs(root, myArrayBuffer, k)
  }
}
```
