#### 方法：递归

**思路**

令 `trim(node)` 作为该节点上的子树的理想答案。我们可以递归地构建该答案。

**算法**

当 $\text{node.val > R}$，那么修剪后的二叉树必定出现在节点的左边。

类似地，当 $\text{node.val < L}$，那么修剪后的二叉树出现在节点的右边。否则，我们将会修剪树的两边。

```java [GoXj8r6W-Java]
class Solution {
    public TreeNode trimBST(TreeNode root, int L, int R) {
        if (root == null) return root;
        if (root.val > R) return trimBST(root.left, L, R);
        if (root.val < L) return trimBST(root.right, L, R);

        root.left = trimBST(root.left, L, R);
        root.right = trimBST(root.right, L, R);
        return root;
    }
}
```
```python [GoXj8r6W-Python]
class Solution(object):
    def trimBST(self, root, L, R):
        def trim(node):
            if not node:
                return None
            elif node.val > R:
                return trim(node.left)
            elif node.val < L:
                return trim(node.right)
            else:
                node.left = trim(node.left)
                node.right = trim(node.right)
                return node

        return trim(root)
```


**复杂度分析** 

* 时间复杂度：$O(N)$，其中 $N$ 是给定的树的全部节点。我们最多访问每个节点一次。

* 空间复杂度：$O(N)$，即使我们没有明确使用任何额外的内存，在最糟糕的情况下，我们递归调用的栈可能与节点数一样大。