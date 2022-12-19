### 解题思路

本题为了简化题目，已经说明了所有的结点都是唯一的，p、q 不同且均存在于给定的二叉树中。因此我们有以下三种情况：

![0408.png](https://pic.leetcode-cn.com/0f4ca3373202d322ee1f210ae7272186021c42ba9a4b5cd7d3b775c98af0b8bd-0408.png)

难点在于如何书写递归函数，不妨这样思考：

- 假设我们从跟结点开始，采用 DFS 向下遍历，如果当前结点到达叶子结点下的空结点时，返回空；如果当前结点为 p 或 q 时，返回当前结点；

- 这样，当我们令 `left = self.lowestCommonAncestor(root.left, p, q)` 时，如果在左子树中找到了 p 或 q，left 会等于 p 或 q，同理，right 也是一样；

- 然后我们进行判断：如果 left 为 right 都不为空，则为情况 1；如果 left 和 right 中只有一个不为空，说明这两个结点在子树中，则根节点到达子树再进行寻找。


### 代码

```python []
class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        if not root or root == p or root == q:
            return root
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)
        if left and right: return root
        return left if left else right
```

```cpp []
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q || root == NULL) return root;
        TreeNode* left = lowestCommonAncestor(root -> left, p, q);
        TreeNode* right = lowestCommonAncestor(root -> right, p, q);
        if (left && right) return root;
        return left ? left : right;
    }
};
```
如果你对递归代码的运行过程有疑问，每日一题的题解 [50 张 ppt 详解递归代码的执行过程](https://leetcode-cn.com/problems/diameter-of-binary-tree/solution/shi-pin-jie-shi-di-gui-dai-ma-de-yun-xing-guo-chen/) 中进行了相关解释。欢迎讨论

### 复杂度分析
- 时间复杂度：$O(n)$。我们需要遍历每一个节点。
- 空间复杂度：$O(n)$，斜二叉树的高度为 $n$。

