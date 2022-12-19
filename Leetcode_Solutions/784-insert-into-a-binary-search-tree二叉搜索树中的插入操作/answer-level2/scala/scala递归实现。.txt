Scala 不推荐使用 return，但此处递归调用，默认返回头节点，应使用 return 关键字。在递归调用函数找到待插入的位置时，该节点为空结点，在此调用本函数，创建一个新节点。
```scala
def insertIntoBST(root: TreeNode, `val`: Int): TreeNode = {
    if (root != null) {
      if (root.value < `val`) {
        root.right = insertIntoBST(root.right, `val`)
      }
      else {
        root.left = insertIntoBST(root.left, `val`)
      }
    } else {
      return new TreeNode(`val`)
    }
    root
  }
```