```
  // 辅助函数，创建节点
  def makeNode(_value: Int, left: TreeNode, right: TreeNode): TreeNode = {
    val ret = new TreeNode(_value)
    ret.left = left
    ret.right = right
    ret
  }

  // 递归复制二叉树
  def clone(node: TreeNode, offset: Int): TreeNode =
    Option(node).map(n =>
      makeNode(n.value + offset, clone(n.left, offset), clone(n.right, offset))
    ).orNull
  
  def generateTrees(n: Int): List[TreeNode] = n match {
    case 0 => Nil
    case _ =>
      val dp: Array[List[TreeNode]] = Array.fill(n + 1)(null :: Nil)
      dp(1) = List(new TreeNode(1))
      2.to(n) foreach { idx =>
        dp(idx) = 1.to(idx).flatMap { root =>
          for {
            left <- dp(root - 1)  // 左子树
            right <- dp(idx - root).map(clone(_, root)) // 右子树需要复制
            middle = makeNode(root, left, right) // 生成二叉树
          } yield middle
        }.toList
      }
      dp.last
  }
```
