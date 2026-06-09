```
object Solution {
  def midOrder(root: TreeNode, buff: scala.collection.mutable.ArrayBuffer[TreeNode]): Unit = {
    if (root == null) return
    midOrder(root.left, buff)
    buff += root
    midOrder(root.right, buff)
  }

  def increasingBST(root: TreeNode): TreeNode = {
    import scala.collection.mutable.ArrayBuffer
    val myArrayBuffer = new ArrayBuffer[TreeNode]()
    midOrder(root, myArrayBuffer)
    for (i <- 0 to myArrayBuffer.length - 2) {
      myArrayBuffer(i).left = null
      myArrayBuffer(i).right = myArrayBuffer(i + 1)
    }
    myArrayBuffer(0)
  }
}
```
