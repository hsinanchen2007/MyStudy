### 解题思路
1. 首先我们要明确什么是递归？

2. 总的来说，递归就是把一个大的问题分解成一个一个小的子问题，注意，子问题的模式必须和原问题一模一样。

3. 按着本题来说，什么是它的子问题呢？
- 那么我们需要真正理解本题的问题到底是什么？
- 本题要我们求出一个最近的公共祖先节点，也就是说我们返回的最终答案是一个节点。
- 那么这个节点它，一定是在根节点，或者是在根节点的左子树，或者是在根节点的右子树。

4. 好了，此时我们就可以看出子问题了。
- 假如这个祖先节点不在原始的根节点，那么它可能在左子树，也就是在左子树的根节点，要么是左子树的左子树或者左子树的右子树，这样我们肯定能去递归寻找答案是否在左子树中。
- 那么同理可得，我们也可以递归寻找答案是否在右子树中。
- 如果我们递归完成发现左子树返回的答案是空节点而右子树不是空节点，那么答案一定在右子树。
- 相反，则在左子树。
- 假如左右子树返回的答案是空的话，那么必然返回根节点，原因是根节点一定是祖先节点。

### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null || root == p || root == q) {
            return root;
        }

        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);

        if (left != null && right != null) {
            return root;
        }

        return (left != null) ? left : right;
    }
}
```