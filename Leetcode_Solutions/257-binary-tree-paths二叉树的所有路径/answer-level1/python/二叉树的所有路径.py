#### 二叉树的定义

首先给出 `TreeNode` 的定义，我们将会在后续的代码实现中使用它。

```Java [def]
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

```Python [def]
class TreeNode(object):
    """ Definition of a binary tree node."""
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
```

#### 方法一：递归

最直观的方法是使用递归。在递归遍历二叉树时，需要考虑当前的节点和它的孩子节点。如果当前的节点*不是*叶子节点，则在当前的路径末尾添加该节点，并递归遍历该节点的每一个孩子节点。如果当前的节点*是*叶子节点，则在当前的路径末尾添加该节点后，就得到了一条从根节点到叶子节点的路径，可以把该路径加入到答案中。

```Java [sol1]
class Solution {
    public void construct_paths(TreeNode root, String path, LinkedList<String> paths) {
        if (root != null) {
            path += Integer.toString(root.val);
            if ((root.left == null) && (root.right == null))  // 当前节点是叶子节点
                paths.add(path);  // 把路径加入到答案中
            else {
                path += "->";  // 当前节点不是叶子节点，继续递归遍历
                construct_paths(root.left, path, paths);
                construct_paths(root.right, path, paths);
            }
        }
    }

    public List<String> binaryTreePaths(TreeNode root) {
        LinkedList<String> paths = new LinkedList();
        construct_paths(root, "", paths);
        return paths;
    }
}
```

```Python [sol1]
class Solution:
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        def construct_paths(root, path):
            if root:
                path += str(root.val)
                if not root.left and not root.right:  # 当前节点是叶子节点
                    paths.append(path)  # 把路径加入到答案中
                else:
                    path += '->'  # 当前节点不是叶子节点，继续递归遍历
                    construct_paths(root.left, path)
                    construct_paths(root.right, path)

        paths = []
        construct_paths(root, '')
        return paths
```

**复杂度分析**

* 时间复杂度：每个节点只会被访问一次，因此时间复杂度为 $O(N)$，其中 $N$ 表示节点数目。
* 空间复杂度：$O(N)$。这里不考虑存储答案 `paths` 使用的空间，仅考虑额外的空间复杂度。额外的空间复杂度为递归时使用的栈空间，在最坏情况下，当二叉树中每个节点只有一个孩子节点时，递归的层数为 $N$，此时空间复杂度为 $O(N)$。在最好情况下，当二叉树为平衡二叉树时，它的高度为 $\log(N)$，此时空间复杂度为 $O(\log(N))$。

#### 方法二：迭代

上面的算法也可以使用迭代（宽度优先搜索）的方法实现。我们维护一个队列，存储节点以及根到该节点的路径。一开始这个队列里只有根节点。在每一步迭代中，我们取出队列中的首节点，如果它*是*一个叶子节点，则将它对应的路径加入到答案中。如果它*不是*一个叶子节点，则将它的所有孩子节点加入到队列的末尾。当队列为空时，迭代结束。

<![1200](https://pic.leetcode-cn.com/Figures/257/257_slide_2.png),![1200](https://pic.leetcode-cn.com/Figures/257/257_slide_3.png),![1200](https://pic.leetcode-cn.com/Figures/257/257_slide_4.png),![1200](https://pic.leetcode-cn.com/Figures/257/257_slide_5.png),![1200](https://pic.leetcode-cn.com/Figures/257/257_slide_6.png),![1200](https://pic.leetcode-cn.com/Figures/257/257_slide_7.png),![1200](https://pic.leetcode-cn.com/Figures/257/257_slide_8.png)>


```Java [sol2]
class Solution {
    public List<String> binaryTreePaths(TreeNode root) {
        LinkedList<String> paths = new LinkedList();
        if (root == null)
            return paths;

        LinkedList<TreeNode> node_stack = new LinkedList();
        LinkedList<String> path_stack = new LinkedList();
        node_stack.add(root);
        path_stack.add(Integer.toString(root.val));
        TreeNode node;
        String path;
        while (!node_stack.isEmpty()) {
            node = node_stack.pollLast();
            path = path_stack.pollLast();
            if ((node.left == null) && (node.right == null))
                paths.add(path);
            if (node.left != null) {
                node_stack.add(node.left);
                path_stack.add(path + "->" + Integer.toString(node.left.val));
            }
            if (node.right != null) {
                node_stack.add(node.right);
                path_stack.add(path + "->" + Integer.toString(node.right.val));
            }
        }
        return paths;
    }
}
```

```Python [sol2]
class Solution:
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        if not root:
            return []
        
        paths = []
        stack = [(root, str(root.val))]
        while stack:
            node, path = stack.pop()
            if not node.left and not node.right:
                paths.append(path)
            if node.left:
                stack.append((node.left, path + '->' + str(node.left.val)))
            if node.right:
                stack.append((node.right, path + '->' + str(node.right.val)))
        
        return paths
```

**复杂度分析**

* 时间复杂度：$O(N)$，每个节点只会被访问一次。
* 空间复杂度：$O(N)$，在最坏情况下，队列中有 $N$ 个节点。