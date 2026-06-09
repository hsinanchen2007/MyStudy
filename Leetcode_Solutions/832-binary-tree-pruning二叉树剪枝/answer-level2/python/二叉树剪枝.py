#### 递归：

我们可以使用递归来解决这个问题。我们用 `containsOne(node)` 函数来判断以 `node` 为根的子树中是否包含 `1`，其不包含 `1` 当且仅当以 `node` 的左右孩子为根的子树均不包含 `1`，并且 `node` 节点本身的值也不为 `1`。

如果 `node` 的左右孩子为根的子树不包含 `1`，那我们就需要把对应的指针置为空。例如当 `node` 的左孩子为根的子树不包含 `1` 时，我们将 `node.left` 置为 `null`。

在递归结束之后，如果整颗二叉树都不包含 `1`，那么我们返回 `null`，否则我们返回原来的根节点。

```Java [sol1]
class Solution {
    public TreeNode pruneTree(TreeNode root) {
        return containsOne(root) ? root : null;
    }

    public boolean containsOne(TreeNode node) {
        if (node == null) return false;
        boolean a1 = containsOne(node.left);
        boolean a2 = containsOne(node.right);
        if (!a1) node.left = null;
        if (!a2) node.right = null;
        return node.val == 1 || a1 || a2;
    }
}
```

```Python [sol1]
class Solution(object):
    def pruneTree(self, root):
        def containsOne(node):
            if not node: return False
            a1 = containsOne(node.left)
            a2 = containsOne(node.right)
            if not a1: node.left = None
            if not a2: node.right = None
            return node.val == 1 or a1 or a2

        return root if containsOne(root) else None
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是树中节点的个数。

* 空间复杂度：$O(H)$，其中 $H$ 是树的高度，为我们在递归时使用的栈空间大小。