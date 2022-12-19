### 解题思路
先序遍历。
对于每一棵树，如果根结点是p,q这一，根结点就是解
如果p,q,分别在左右树，根结点就是解
否则解在左或右子树中
1. ### 代码

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
    if(!root) return null
    if(root.val===p.val||root.val===q.val) return root
    let left=lowestCommonAncestor(root.left,p,q)
    let right=lowestCommonAncestor(root.right,p,q)
    if(left&&right) return root
    else return left||right
};
```