#### 如何遍历一棵树

有两种通用的遍历树的策略：

* *深度优先搜索*（`DFS`）

  在这个策略中，我们采用`深度`作为优先级，以便从跟开始一直到达某个确定的叶子，然后再返回根到达另一个分支。

  深度优先搜索策略又可以根据根节点、左孩子和右孩子的相对顺序被细分为`先序遍历`，`中序遍历`和`后序遍历`。

* *宽度优先搜索*（`BFS`）

  我们按照高度顺序一层一层的访问整棵树，高层次的节点将会比低层次的节点先被访问到。

下图中的顶点按照访问的顺序编号，按照 `1-2-3-4-5` 的顺序来比较不同的策略。

![102.png](https://pic.leetcode-cn.com/8e21fed563ab0c9564fb6aaba01934ee6986e0097af51e21e792bee1f4eef4d4-102.png)
{:align=center}

本问题就是用宽度优先搜索遍历来划分层次：`[[1], [2, 3], [4, 5]]`。

#### 方法 1：迭代

**算法**

首先，定义树的存储结构 `TreeNode`。

```Java []
/* Definition for a binary tree node. */
public class TreeNode {
  int val;
  TreeNode left;
  TreeNode right;

  TreeNode(int x) {
    val = x;
  }
}
```

```Python []
class TreeNode(object):
    """ Definition of a binary tree node."""
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
```

从根节点开始依次迭代，弹出栈顶元素输出到输出列表中，然后依次压入它的所有孩子节点，按照从上到下、从左至右的顺序依次压入栈中。

因为深度优先搜索后序遍历的顺序是从下到上、从左至右，所以需要将输出列表逆序输出。

```Java []
class Solution {
  public List<Integer> postorderTraversal(TreeNode root) {
    LinkedList<TreeNode> stack = new LinkedList<>();
    LinkedList<Integer> output = new LinkedList<>();
    if (root == null) {
      return output;
    }

    stack.add(root);
    while (!stack.isEmpty()) {
      TreeNode node = stack.pollLast();
      output.addFirst(node.val);
      if (node.left != null) {
        stack.add(node.left);
      }
      if (node.right != null) {
        stack.add(node.right);
      }
    }
    return output;
  }
}
```

```Python []
class Solution(object):
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if root is None:
            return []

        stack, output = [root, ], []
        while stack:
            root = stack.pop()
            output.append(root.val)
            if root.left is not None:
                stack.append(root.left)
            if root.right is not None:
                stack.append(root.right)
                
        return output[::-1]
```

**复杂度分析**

* 时间复杂度：访问每个节点恰好一次，因此时间复杂度为 $O(N)$，其中 $N$ 是节点的个数，也就是树的大小。
* 空间复杂度：取决于树的结构，最坏情况需要保存整棵树，因此空间复杂度为 $O(N)$。