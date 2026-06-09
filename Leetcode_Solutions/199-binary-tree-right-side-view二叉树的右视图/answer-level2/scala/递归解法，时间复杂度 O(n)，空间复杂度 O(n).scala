__如果想理解这道题，首先我们需要了解树的递归遍历，这里展示解法：__

__如果小伙伴们已经掌握则可以跳到下一段：）__

核心思想为：拿到一个**节点**就把他存下来，然后对这个**节点**的**左右子节点**重复进行这一过程

详细代码及过程注释如下：

```scala []
import scala.collection.mutable
obejct TraversalTree {
    // 递归遍历树方法
    def traversalTree(root: TreeNode): List[Int] = {
        // 定义一个集合存储遍历结果
        val result = new mutable.ListBuffer[Int]()
        // 开始遍历
        traversalNode(root, result)
        result.toList
    }

    // 遍历每一个节点
    private def traversalNode(root: TreeNode, result: mutable.ListBuffer[Int]): Unit = {
        if (root != null) {
            // 如果根节点不为空，就把它的值存到遍历结果集里
            result.append(root.value)
            // 继续将根的左右子节点作为新的根，递归遍历
            traversalNode(root.left, result)
            traversalNode(root.right, result)
        }
    }
}
```

__接下来我们思考一下树的递归遍历与这道题间的关系：__

1.这道题树的每一层只保存一个节点

2.保存的节点为最右侧节点

__基于这两个要求，我们想一下如何处理：__

1.可以创建一个当前**深度**标记变量`deep`，让`deep`与遍历的结果集合`result.length`进行比较，如果`deep`大于`result.length`，就说明这一层还没有将**最右节点**放入结果集，反之则是放过了。这样就能达成每层只放一个节点的逻辑

2.调整一下**递归时遍历左右节点的顺序**，让右侧节点先开始遍历，就能配合**处理1**。这样就能达成优先放入最右侧节点的逻辑

__想清楚了逻辑，就可以开始编写代码了，详细代码和逻辑注释如下：__
```scala []
import scala.collection.mutable
object BinaryTreeRightSideView {
  // 找到二叉树的右视图
  def rightSideView(root: TreeNode): List[Int] = {
    // 定义一个集合存储右视图
    val result = new mutable.ListBuffer[Int]()
    // 检查每一个节点
    // 对应处理1，新增一个变量deep记录深度，并初始化为1
    checkNode(root, result, 1)
    result.toList
  }

  private def checkNode(root: TreeNode, result: mutable.ListBuffer[Int], deep: Int): Unit = {
    if (root != null) {
      // 对应处理1，每次根据deep深度和result的结果个数判断这一层是否已经添加了右节点
      // 如果添加了右节点，就什么都不做。如果没有添加，就添加
      if (result.length < deep) {
        result.append(root.value)
      }
      
      // 对应处理2，先遍历右节点，再遍历左节点
      // 注意层级深度需要+1
      checkNode(root.right, deep + 1, result)
      checkNode(root.left, deep + 1, result)
    }
  }
}
```

__复杂度分析__

- 时间复杂度：$O(n)$
  
  我们需要遍历树的每一个节点，树一共有 $n$ 个节点，所以时间复杂度为 $n$
- 空间复杂度：$O(n)$
  
  因为是递归遍历，存在方法栈的空间占用，占用大小与树的节点数 $n$ 相等，所以空间复杂的为 $n$
