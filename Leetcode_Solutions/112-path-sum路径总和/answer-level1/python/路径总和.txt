#### 二叉树定义

首先，定义一下二叉树的结构 `TreeNode`。

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

#### 方法 1：递归

最直接的方法就是利用递归，遍历整棵树：如果当前节点不是叶子，对它的所有孩子节点，递归调用 `hasPathSum` 函数，其中 sum 值减去当前节点的权值；如果当前节点是叶子，检查 sum 值是否为 0，也就是是否找到了给定的目标和。

```Java []
class Solution {
  public boolean hasPathSum(TreeNode root, int sum) {
    if (root == null)
      return false;

    sum -= root.val;
    if ((root.left == null) && (root.right == null))
      return (sum == 0);
    return hasPathSum(root.left, sum) || hasPathSum(root.right, sum);
  }
}
```

```Python []
class Solution:
    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        if not root:
            return False

        sum -= root.val
        if not root.left and not root.right:  # if reach a leaf
            return sum == 0
        return self.hasPathSum(root.left, sum) or self.hasPathSum(root.right, sum)
```

**复杂度分析**

* 时间复杂度：我们访问每个节点一次，时间复杂度为 $O(N)$ ，其中 $N$ 是节点个数。
* 空间复杂度：最坏情况下，整棵树是非平衡的，例如每个节点都只有一个孩子，递归会调用 $N$ 次（树的高度），因此栈的空间开销是 $O(N)$ 。但在最好情况下，树是完全平衡的，高度只有 $\log(N)$，因此在这种情况下空间复杂度只有 $O(\log(N))$ 。

#### 方法 2：迭代

**算法**

我们可以用栈将递归转成迭代的形式。深度优先搜索在除了最坏情况下都比广度优先搜索更快。最坏情况是指满足目标和的 `root->leaf` 路径是最后被考虑的，这种情况下深度优先搜索和广度优先搜索代价是相通的。

> 利用深度优先策略访问每个节点，同时更新剩余的目标和。

所以我们从包含根节点的栈开始模拟，剩余目标和为 `sum - root.val`。

然后开始迭代：弹出当前元素，如果当前剩余目标和为 `0` 并且在叶子节点上返回 `True`；如果剩余和不为零并且还处在非叶子节点上，将当前节点的所有孩子以及对应的剩余和压入栈中。


<![image.png](https://pic.leetcode-cn.com/e18a2fa85437c6845410e8fb03af803d81a0ff2bca9435a3b620048011633e3d-image.png),![image.png](https://pic.leetcode-cn.com/bd53583500d30b00e1934b38c2cfcee77b694b7cbda05f9cd8c4ebc3bac048fb-image.png),![image.png](https://pic.leetcode-cn.com/6b2eb786cef2a280bc7797ed598db902eb44126e9a86caf82348bb710d2563d1-image.png),![image.png](https://pic.leetcode-cn.com/3a71471c22fc39f970e8cb9d15f7c558d0192f99fd4327ec3404732e347a23ca-image.png),![image.png](https://pic.leetcode-cn.com/fb3e4d92ee963464f3ad9c19091b8639457c9a127272a2792935697f5abe38ca-image.png),![image.png](https://pic.leetcode-cn.com/4c31a92093b954e27be6e9e4cd4927b56f250df4d9276c3aebc45bf76fccaa52-image.png),![image.png](https://pic.leetcode-cn.com/e93bc6096d8911c81a7e7015f9354c57d3b7db3e1e232b7e823cb1d85730ef7d-image.png),![image.png](https://pic.leetcode-cn.com/f9c5e3b9bd97e209556f29622af22af441e96d7b1f335563d01b8440348048e5-image.png)>

```Java []
class Solution {
  public boolean hasPathSum(TreeNode root, int sum) {
    if (root == null)
      return false;

    LinkedList<TreeNode> node_stack = new LinkedList();
    LinkedList<Integer> sum_stack = new LinkedList();
    node_stack.add(root);
    sum_stack.add(sum - root.val);

    TreeNode node;
    int curr_sum;
    while ( !node_stack.isEmpty() ) {
      node = node_stack.pollLast();
      curr_sum = sum_stack.pollLast();
      if ((node.right == null) && (node.left == null) && (curr_sum == 0))
        return true;

      if (node.right != null) {
        node_stack.add(node.right);
        sum_stack.add(curr_sum - node.right.val);
      }
      if (node.left != null) {
        node_stack.add(node.left);
        sum_stack.add(curr_sum - node.left.val);
      }
    }
    return false;
  }
}
```

```Python []
class Solution:
    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        if not root:
            return False

        de = [(root, sum - root.val), ]
        while de:
            node, curr_sum = de.pop()
            if not node.left and not node.right and curr_sum == 0:  
                return True
            if node.right:
                de.append((node.right, curr_sum - node.right.val))
            if node.left:
                de.append((node.left, curr_sum - node.left.val))
        return False
```

**复杂度分析**

* 时间复杂度：和递归方法相同是 $O(N)$。
* 空间复杂度：当树不平衡的最坏情况下是 $O(N)$ 。在最好情况（树是平衡的）下是 $O(\log N)$。