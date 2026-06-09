### 解题思路

``二叉树`` 类型的题目，最难的不是 ``递归``，而是找到 ``递归`` 的策略，以下为这道题的思路：

- 如果 ``root`` 为 ``null``，那么以 ``root`` 为根节点的 ``二叉树`` 中找不到 ``p`` 和 ``q`` 的最近公共祖先，此时返回 ``null``
- 如果 ``root.val === p.val`` 或者 ``root.val === q.val``，说明 ``p`` 和 ``q`` 中有一个节点为 ``root`` 节点，有一个节点在 ``root`` 的左子树或者右子树，此时返回 ``root``
- 如果不符合上面两个条件，此时分别往左子树和右子树递归
- 递归完毕，此时分几种情况讨论：
    1. 如果如果左右子树能分别找到 ``p`` 和 ``q``，说明 ``root`` 节点为最近的公共祖先
    2. 如果只有左子树能找到 ``p`` 和 ``q``，说明 ``left`` 节点为最近的公共祖先
    3. 如果只有右子树能找到 ``p`` 和 ``q``，说明 ``right`` 节点为最近的公共祖先

说明：这里的策略是以左右子树中第一个找到的节点为准，理解这个才能写出递归。

### 代码

```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 */
var lowestCommonAncestor = function(root, p, q) {
    if (!root) {
        return null
    }
    if (root.val === p.val || root.val === q.val) {
        return root
    }
    // 从左子树里找到有一个跟 p 或者 q 相等的节点
    root.left = lowestCommonAncestor(root.left, p, q)
    // 从右子树里找到有一个跟 p 或者 q 相等的节点
    root.right = lowestCommonAncestor(root.right, p, q)
    // 左右子树以第一个找到的节点为准
    // 如果左右子树都有结果，说明 root 为最近的公共祖先
    // 如果只有左子树有结果，那么 left 为最近的公共祖先
    // 如果只有右子树有结果，那么 left 为最近的公共祖先
    // 如果都没有结果，那么返回 null
    if (root.left && root.right) {
        return root
    } else if (root.left) {
        return root.left
    } else if (root.right) {
        return root.right
    }
    return null
};
```