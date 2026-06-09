#### 方法一：深度优先搜索

我们对树进行深度优先搜索，对于当前节点 `node`，如果  `node.val` 小于等于 `L`，那么只需要继续搜索它的右子树；如果 `node.val` 大于等于 `R`，那么只需要继续搜索它的左子树；如果 `node.val` 在区间 `(L, R)` 中，则需要搜索它的所有子树。

我们在代码中用递归和迭代的方法分别实现了深度优先搜索。

**递归实现深度优先搜索**


```Java [sol1]
class Solution {
    int ans;
    public int rangeSumBST(TreeNode root, int L, int R) {
        ans = 0;
        dfs(root, L, R);
        return ans;
    }

    public void dfs(TreeNode node, int L, int R) {
        if (node != null) {
            if (L <= node.val && node.val <= R)
                ans += node.val;
            if (L < node.val)
                dfs(node.left, L, R);
            if (node.val < R)
                dfs(node.right, L, R);
        }
    }
}
```

```Python [sol1]
class Solution(object):
    def rangeSumBST(self, root, L, R):
        def dfs(node):
            if node:
                if L <= node.val <= R:
                    self.ans += node.val
                if L < node.val:
                    dfs(node.left)
                if node.val < R:
                    dfs(node.right)

        self.ans = 0
        dfs(root)
        return self.ans
```

**迭代实现深度优先搜索**

```Java [sol2]
class Solution {
    public int rangeSumBST(TreeNode root, int L, int R) {
        int ans = 0;
        Stack<TreeNode> stack = new Stack();
        stack.push(root);
        while (!stack.isEmpty()) {
            TreeNode node = stack.pop();
            if (node != null) {
                if (L <= node.val && node.val <= R)
                    ans += node.val;
                if (L < node.val)
                    stack.push(node.left);
                if (node.val < R)
                    stack.push(node.right);
            }
        }
        return ans;
    }
}
```

```Python [sol2]
class Solution(object):
    def rangeSumBST(self, root, L, R):
        ans = 0
        stack = [root]
        while stack:
            node = stack.pop()
            if node:
                if L <= node.val <= R:
                    ans += node.val
                if L < node.val:
                    stack.append(node.left)
                if node.val < R:
                    stack.append(node.right)
        return ans
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是树中的节点数目。

* 空间复杂度：$O(H)$，其中 $H$ 是树的高度。